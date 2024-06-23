#include "wire.h"

typedef std::map<wire*, int>::iterator wire_iter;

port::port(Unit* belonged_unit, int port_side, int port_width=1, std::string port_name="") {
    assert(belonged_unit != NULL);
    assert(1 <= port_width && port_width <= SIGNAL_MAX);

    this->belonged_unit = belonged_unit;
    this->port_width    = port_width;
    this->port_name     = port_name;
    this->port_bits     = 0;
    this->port_side     = port_side;
    this->port_mask     = bitmap::bitmask_gen(0, port_width);
    this->wire_alloc    = new bitmap(port_width);
}

port::~port() {
    delete this->wire_alloc;
}

void port::link(wire* connected_wire, int offset) {
    assert(0 <= offset && offset < port_width);

    int width = connected_wire->get_width();
    assert(offset + width <= SIGNAL_MAX);

    mask_t collision = wire_alloc->get_bitmap_bits()
                     & bitmap::bitmask_gen(offset, offset + width);
    assert(collision == BITMAP_FREE_ALL);

    wire_alloc->bitmap_set(offset, offset + width);
    wires[connected_wire] = offset;
}

void port::send() {
    assert(port_side & port::SEND);

    wire_iter it;
    for (it = wires.begin(); it != wires.end(); it++) {
        wire*  wire_seg = (*it).first;
        int    offset   = (*it).second;
        int    width    = wire_seg->get_width();
        mask_t sig_mask = bitmap::bitmask_gen(offset, offset + width);
        wire_seg->transport((port_bits & sig_mask) >> offset);
    }
}

void port::receive(sig_t signal, wire* connected_wire) {
    assert(port_side & port::RECEIVE);

    wire_iter pt;
    assert((pt = wires.find(connected_wire)) != wires.end());

    int offset = (*pt).second;
    int width  = connected_wire->get_width();

    sig_t value = signal << offset;
    value      &= bitmap::bitmask_gen(offset, offset + width);
    port_bits  |= value; 
    port_bits  &= port_mask;

    belonged_unit->receive();
}

sig_t port::read() {
    return port_bits & port_mask;
}

void port::write(sig_t signal) {
    port_bits = signal & port_mask;
}


wire::wire(int wire_width = 1, std::string wire_name = "") {
    assert(1 <= wire_width && wire_width <= SIGNAL_MAX);

    this->wire_width = wire_width;
    this->wire_name  = wire_name;
}

void wire::link(port* connecting_port, bool connecting_type) {
    if (connecting_type)
        this->send_port    = connecting_port;
    else
        this->receive_port = connecting_port;
}

void wire::transport(sig_t signal) {
    assert(this->send_port != NULL && this->receive_port != NULL);

    this->receive_port->receive(signal, this);
}
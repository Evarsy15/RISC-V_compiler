#include "unit.h"
#include <assert.h>
#include <vector>
#include <string>

#define sig unsigned long long int

class wire;

/*
    port : data send/receive unit.
*/
class port {
  public:
    port(Unit* belonged_unit, bool port_type, int port_width, std::string port_name);
    
    void link   (wire* connected_wire, int offset);
    void send   (sig signal);
    void receive(sig signal, wire* wire);

    std::string get_name() { return port_name; }
    void print_name() { std::cout << port_name; }
    void print_info() {}
  
  private:
    bool  port_type;  // 0 : receiving port, 1 : sending port
    int   port_width;
    long  port_bits;

    Unit* belonged_unit;
    
    // A bundle of wires is described in a list of pairs <wire, int> 
    // which has a wire pointer and its offset in the port.
    std::vector< std::pair<wire*, int> > wires;
    /* bitmap */ 
    unsigned long wire_bitmap; // bitmap for wire linking
    
    std::string port_name;
};

port::port(Unit* belonged_unit, bool port_type=0, int port_width=1, std::string port_name="") {
    assert(belonged_unit != NULL);
    assert(port_width >= 1);

    this->belonged_unit = belonged_unit;
    this->port_type     = port_type;
    this->port_width    = port_width;
    this->port_name     = port_name;
    this->port_bits     = 0;
    this->wire_bitmap   = 0;
}

void port::link(wire* connected_wire, int offset) {
    int width = connected_wire->get_width();
}

void port::send(sig signal) {
    assert(port_type == 1);
    
}

/*
    wire : 
*/
class wire {
  public:
    wire(int width, std::string wire_name);
    
    void link(port* connected_port, bool port_type);
    void transport(sig signal);
    
    int get_width() { return width; }
    std::string get_name() { return wire_name; }
    void print_name() { std::cout << wire_name; }

  private:
    port* send_port;
    port* receive_port;
    int   width;

    std::string wire_name;
};

wire::wire(int width=1, std::string wire_name="") {
    assert(width >= 1);

    this->width     = width;
    this->wire_name = wire_name;
}

void wire::link(port* connected_port, bool port_type) {
    if (port_type)
        this->send_port    = connected_port;
    else
        this->receive_port = connected_port;
}

void wire::transport(sig signal) {
    assert(this->send_port != NULL && this->receive_port != NULL);
    this->receive_port->receive(signal, this);
}
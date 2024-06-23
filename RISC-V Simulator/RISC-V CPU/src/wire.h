#ifndef WIRE_H
#define WIRE_H

#include <assert.h>
#include <map>
#include <string>
#include "unit.h"
#include "utils.h"
#include "bitmap.h"

#define SIGNAL_MAX 64

class wire;

/*
    port : data send/receive unit.
*/
class port {
  public:
    port(Unit* belonged_unit, int port_side, int port_width, std::string port_name);
    ~port();

    void  link    (wire* connected_wire, int offset);
    void  send    ();
    void  receive (sig_t signal, wire* connected_wire);
    sig_t read    ();
    void  write   (sig_t signal);

    std::string get_name()   { return port_name; }
    void        print_name() { std::cout << port_name; }

    const static int RECEIVE = 1;
    const static int SEND    = 2;
  
  private:
    int    port_width; // port width
    sig_t  port_bits;  // actual port data
    int    port_side;  // mask for port side (receive / send / both)
    mask_t port_mask;  // mask for port_bits by port_width

    Unit* belonged_unit;
    
    // A bundle of wires is described in a map of pairs <wire, int> 
    // which has a wire pointer and its offset in the port.
    std::map<wire*, int> wires;
    bitmap* wire_alloc; // bitmap for wire linking
    
    std::string port_name;
};

/*
    wire : data transporting wire.
*/
class wire {
  public:
    wire(int wire_width, std::string wire_name);
    
    void link(port* connecting_port, bool connecting_type);
    void transport(sig_t signal);
    
    int         get_width()  { return wire_width; }
    std::string get_name()   { return wire_name; }
    void        print_name() { std::cout << wire_name; }

  private:
    port* send_port;
    port* receive_port;
    int   wire_width;

    std::string wire_name;
};

#endif
#ifndef UNIT_H
#define UNIT_H

#include <iostream>

class Unit {
  public:
    virtual void send() = 0;    // send signals along output ports
    virtual void receive() = 0; // receive signals along input ports
    virtual void cycle() = 0;   // for synchronous units
    
    // virtual void print_info()=0;
    static  void print_null() { std::cout << "Unit not allocated\n";}
};

#endif
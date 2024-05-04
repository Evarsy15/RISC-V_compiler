#ifndef UNIT_H
#define UNIT_H

#include <iostream>

class Unit {
  public:
    virtual void print_info();
    virtual void cycle(); // for synchronous units
    static  void print_null() { std::cout << "Unit not allocated\n";}
};

#endif
/*
    Combinatorial Logic Units
*/

#include <string>
#include <assert.h>
#include "unit.h"

/*
    Wire connects any two units.
    - send_unit    : A unit which sends the signal along the wire.
    - receive_unit : A unit which receives the signal along the wire.
*/


class AND {
  public:
    AND() { this->name = "AND"; }
    AND(std::string name) { this->name = name; }

    bool set_input(bool in1, bool in2) { 
      this->in1 = in1;
      this->in2 = in2;
      this->out = in1 && in2;
    }
    bool get_output() { 
      return this->out; 
    }
  
  private:
    bool in1; bool in2; bool out;
    std::string name;
};

class OR {
  public:
    OR() {}
  
  private:
};

class MUX {
  public:
    MUX(int port_num, std::string name) {}

  private:
    short port_num; // input port num
};
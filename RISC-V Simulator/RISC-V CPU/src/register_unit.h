#ifndef REGISTER_UNIT_H
#define REGISTER_UNIT_H

#include <string.h>
#include "unit.h"
#include "wire.h"
#include "utils.h"

enum RegisterType {
  X, // integer
  F, // float-point
  V  // vector
};

enum SpecialReg{

};

class RegisterUnit : public Unit {
  public:
    RegisterUnit(std::string  reg_type, std::string reg_name);
    RegisterUnit(RegisterType reg_type, std::string reg_name);
    ~RegisterUnit();
    
    void  send();
    void  receive();
    void  cycle();   // register
    sig_t read ();
    void  write(sig_t);
    
  private:
    port* reg_port;

    RegisterType reg_type;
    uid_t        reg_id;
    std::string  reg_name;

    static uid_t reg_id_gen;
};

#endif
/*
    Register Unit
*/

#include "register_unit.h"

uid_t RegisterUnit::reg_id_gen = 0;

RegisterUnit::RegisterUnit(RegisterType reg_type, std::string reg_name) {
    /*
        reg_t type check section
    */
   
   this->reg_port = new port();
   
   // Intiialize Register Unit config.
   this->reg_type = reg_type;
   this->reg_name = reg_name;
   this->reg_id   = RegisterUnit::reg_id_gen++;
}

void RegisterUnit::send() {

}
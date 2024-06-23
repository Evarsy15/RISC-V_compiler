#ifndef ALU_H
#define ALU_H

#include "unit.h"
#include "wire.h"
#include "utils.h"
#include <string>

#define ALUOP_LEN 4

class ALU : public Unit {
  public:
    ALU(std::string alu_name);
    ~ALU();

    static sig_t operate(sig_t, sig_t, sig_t); // execute operation
    

    void send();
    void receive();
    void cycle() {} // combinatorial unit

    uid_t       get_id()     { return alu_id; }
    std::string get_name()   { return alu_name; }
    void        print_name() { std::cout << alu_name; }
  
  private:
    port* in1;  // ALU Source 1
    port* in2;  // ALU Source 2
    port* ctrl; // ALU Opcode
    port* out;  // ALU Outcome

    static uid_t alu_id_gen;
    uid_t        alu_id;
    std::string  alu_name;

    enum ALUopcode {
      INVALID,

    };
};

class ADDER : public Unit {
  public:
    ADDER(std::string adder_name);
    ~ADDER();

    void send();
    void receive();
    void cycle() {} // combinatorial unit

    uid_t       get_id()     { return adder_id; }
    std::string get_name()   { return adder_name; }
    void        print_name() { std::cout << adder_name; }

  private:
    port* in1;
    port* in2;
    port* out;

    static uid_t adder_id_gen;
    uid_t        adder_id;
    std::string  adder_name;
};

#endif
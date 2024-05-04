#ifndef ALU_H
#define ALU_H

#include "unit.h"
#include "wire.h"
#include <string>

enum ALUopcode {
    INVALID,

};

class ALU {
  public:

  private:
    long long int src1;
    long long int src2;
    ALUopcode     aluop;
    long long int dest;
    std::string name;
};

class ADDER {
  public:
    
  private:
    static unsigned int ADDER_ID_GEN;
    
};

#endif
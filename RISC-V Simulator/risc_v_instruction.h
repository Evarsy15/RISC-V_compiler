#ifndef RISC_V_INSTRUCTION
#define RISC_V_INSTRUCTION

#include <iostream>
#include <string>

enum opcode {
    INVALID,
    NOP,
    
    ADD, SUB,
    SLL, SRL, SRA,
    AND, OR,  XOR,
    
    LUI, AUIPC, ADDI,
    SLLI, SRLI, SRAI,
    ANDI, ORI,  XORI,

    JAL, JALR,
    BEQ, BNE, BLT, BGE,

    LW, SW, LD, SD,

    // "M" Extension
    MUL, DIV, REM,
    MULI, DIVI, REMI,

    // "A" Extension
    LR, SC,
    AMOSWAP, AMOADD,
    AMOAND, AMOOR, AMOXOR,
    AMOMAX, AMOMIN,

    // "F" Extension
    FADD, FSUB, FMUL, FDIV,
    FSQRT, FMIN, FMAX,
    FMADD, FMSUB, FNMADD, FNMSUB,
    
};

enum operand_type { W, D };

enum reg_type { x, f };

struct reg_info {
    reg_type reg_type;
    int      reg_num;
    bool is_valid_info() { return (0 <= reg_num) && (reg_num < 32); }
};

typedef
struct RISC_V_Instruction {
    std::string inst;
    unsigned    inst_binary;
    
    opcode   opcode;
    reg_info dest;
    reg_info src[3];
    

    // For debugging
    void print_instruction() { std::cout << inst; }
} RISC_V_Instruction;



#endif
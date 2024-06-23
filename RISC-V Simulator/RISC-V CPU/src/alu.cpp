#include "alu.h"

uid_t ALU::alu_id_gen = 0;
uid_t ADDER::adder_id_gen = 0;

ALU::ALU(std::string alu_name = "alu") {
    this->alu_name = alu_name;
    this->alu_id   = ALU::alu_id_gen++;

    this->in1  = new port(this, port::RECEIVE, SIGNAL_MAX, alu_name + "_in1");
    this->in2  = new port(this, port::RECEIVE, SIGNAL_MAX, alu_name + "_in2");
    this->ctrl = new port(this, port::RECEIVE, ALUOP_LEN,  alu_name + "_ctrl");
    this->out  = new port(this, port::SEND,    SIGNAL_MAX, alu_name + "_out");
}

ALU::~ALU() {
    delete this->in1;
    delete this->in2;
    delete this->out;
}

void ALU::receive() {
    sig_t src1  = in1->read();
    sig_t src2  = in2->read();
    sig_t aluop = ctrl->read();

    sig_t res   = ALU::operate(src1, src2, aluop);
    
    out->write(res);

    this->send();
}

void ALU::send() {
    out->send();
}

ADDER::ADDER(std::string adder_name = "adder") {
    this->adder_name = adder_name;
    this->adder_id   = ADDER::adder_id_gen++;

    this->in1 = new port(this, port::RECEIVE, SIGNAL_MAX, adder_name + "_in1");
    this->in2 = new port(this, port::RECEIVE, SIGNAL_MAX, adder_name + "_in2");
    this->out = new port(this, port::SEND,    SIGNAL_MAX, adder_name + "_out");
}

ADDER::~ADDER() {
    delete this->in1;
    delete this->in2;
    delete this->out;
}

void ADDER::receive() {
    sig_t in1_val = in1->read();
    sig_t in2_val = in2->read();

    out->write(in1_val + in2_val);

    this->send(); // combinatorial logic
}

void ADDER::send() {
    out->send();
}

sig_t ALU::operate(sig_t src1, sig_t src2, sig_t aluop) {
    
}
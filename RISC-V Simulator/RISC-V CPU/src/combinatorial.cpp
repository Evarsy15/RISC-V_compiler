#include "combinatorial.h"

uid_t AND::and_id_gen = 0;
uid_t OR ::or_id_gen  = 0;

AND::AND(std::string and_name = "and") {
    this->and_name = and_name;
    this->and_id   = AND::and_id_gen++;

    this->in1      = new port(this, port::RECEIVE, 1, and_name + "_in1");
    this->in2      = new port(this, port::RECEIVE, 1, and_name + "_in2");
    this->out      = new port(this, port::SEND,    1, and_name + "_out");
}

AND::~AND() {
    delete this->in1;
    delete this->in2;
    delete this->out;
}

void AND::receive() {
    sig_t in1_val = in1->read();
    sig_t in2_val = in2->read();
    out->write(in1_val & in2_val);
    
    this->send(); // combinatorial logic
}

void AND::send() {
    out->send();
}

OR::OR(std::string or_name = "or") {
    this->or_name = or_name;
    this->or_id   = OR::or_id_gen++;
    
    this->in1     = new port(this, port::RECEIVE, 1, or_name + "_in1");
    this->in2     = new port(this, port::RECEIVE, 1, or_name + "_in2");
    this->out     = new port(this, port::SEND,    1, or_name + "_out");
}

OR::~OR() {
    delete this->in1;
    delete this->in2;
    delete this->out;
}

void OR::receive() {
    sig_t in1_val = in1->read();
    sig_t in2_val = in2->read();
    out->write(in1_val | in2_val);
    
    this->send(); // combinatorial logic
}

void OR::send() {
    out->send();
}

MUX::MUX(int port_num, std::string mux_name = "mux") {
    assert(port_num >= 1);

    this->mux_name = mux_name;
    this->mux_id   = MUX::mux_id_gen++;

    this->port_num = port_num;
    this->in.resize(port_num);
    for (int i=0; i<port_num; i++) {
        this->in.push_back(
                    new port(this, port::RECEIVE, SIGNAL_MAX, 
                                   mux_name + "_in" + std::to_string(i))
                );
    }
    this->ctrl = new port(this, port::RECEIVE, bits_required(port_num), 
                                mux_name + "_ctrl");
    this->out  = new port(this, port::SEND, SIGNAL_MAX, mux_name + "_out");
}

MUX::~MUX() {
    std::vector<port*>::iterator it;
    for (it = in.begin(); it != in.end(); it++)
        delete (*it);
    delete out;
}

void MUX::receive() {
    sig_t ctrl_value = ctrl->read();

    assert(ctrl_value < port_num);
    sig_t selected_value = in[ctrl_value]->read();
    out->write(selected_value);

    this->send();
}

void MUX::send() {
    out->send();
}
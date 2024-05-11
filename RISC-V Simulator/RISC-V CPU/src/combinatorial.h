/*
    Combinatorial Logic Units
*/

#include <string>
#include <vector>
#include <assert.h>
#include "unit.h"
#include "wire.h"
#include "utils.h"

class AND: public Unit {
  public:
    AND(std::string and_name);
    ~AND();

    void send();
    void receive();
    void cycle() {} // combinatorial unit
  
  private:
    port* in1;
    port* in2;
    port* out;

    static uid_t and_id_gen;
    uid_t        and_id;
    std::string  and_name;
};

class OR: public Unit {
  public:
    OR(std::string or_name);
    ~OR();

    void send();
    void receive();
    void cycle() {} // combinatorial unit

    uid_t       get_id()     { return or_id; }
    std::string get_name()   { return or_name; }
    void        print_name() { std::cout << or_name; }
    
  private:
    port* in1;
    port* in2;
    port* out;

    static uid_t or_id_gen;
    uid_t        or_id;
    std::string  or_name;
};

class MUX : public Unit {
  public:
    MUX(int port_num, std::string name);
    ~MUX();

    void send();
    void receive();
    void cycle() {} // combinatrorial unit

  private:
    int port_num; // input port num
    std::vector<port*> in;
    port* ctrl;
    port* out;

    static uid_t mux_id_gen;
    uid_t        mux_id;
    std::string  mux_name;
};
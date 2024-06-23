#ifndef NFA_H
#define NFA_H

#include <map>
#include <set>
#include <string>
using namespace std;

class NFA {
    public:
    struct state {
        string name; // state name
        bool accept; // accept state or not
    };

    const static char epsilon = '\0';

    NFA() {}
    NFA(set<char> symbol_set);
    NFA(set<state> state_set, set<char> symbol_set, state start_state);

    bool add_state(string, bool);
    bool add_transition(string, char, string);
    bool delete_state(string);
    bool delete_transition(string, char, string);

    bool is_accept(string input);

    bool  is_valid_state(string);
    state get_state(string);

    void print_status();

    private:
    set<state> state_set;  // set of states
    set<char>  symbol_set; // set of input symbols (alphabets)
    map<pair<state, char>, set<state>> transition; // transition function
    state start_state;     // start state
    
    set<string> name_set;  // set of names of state
};

#endif
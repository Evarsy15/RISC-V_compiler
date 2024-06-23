#ifndef DFA_H
#define DFA_H

#include <map>
#include <set>
#include <string>
using namespace std;

class DFA {
    public:
    DFA() {}
    DFA(set<char> symbol_set);

    bool set_start_state(string name);
    bool add_state(string name, bool accept);
    bool add_transition(string start, char symbol, string dest);
    bool delete_state(string name);
    bool delete_transition(string start, char symbol, string dest);

    bool is_accepted(string input);
    bool is_valid_state(string name);
    bool is_valid_symbol(char symbol);

    private:
    string            start_state;
    set<string>       state_set;
    set<char>         symbol_set;
    map<string, bool> accept_table;
    map<pair<string, char>, string> transition;
    
};

#endif
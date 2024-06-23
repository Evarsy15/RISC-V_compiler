#include "dfa.h"

/*
    Constructor #1.
*/
DFA::DFA(set<char> symbol_set) {
    this->symbol_set = symbol_set;
}

/*
    Sets start state of DFA by input state.
*/
bool DFA::set_start_state(string name) {
    if (is_valid_state(name)) {
        this->start_state = name;
        return true;
    } else return false;
}

/*
    Adds a state of DFA with given name.
*/
bool DFA::add_state(string name, bool accept) {
    if (!is_valid_state(name)) {
        state_set.insert(name);
        accept_table[name] = accept;
        return true;
    } else return false;
}

/*
    Adds a transition of DFA.
*/
bool DFA::add_transition(string start, char symbol, string dest) {
    if (is_valid_state(start) && is_valid_state(dest) && is_valid_symbol(symbol)) {
        transition[make_pair(start, symbol)] = dest;
        return true;
    } else return false;
}

/*
    Returns whether the input string is accepted by DFA.
*/
bool DFA::is_accepted(string input) {
    int    length = input.length();
    string state  = start_state;
    for (int i=0; i<length; i++) {
        char x = input[i];
        state = transition[make_pair(state, x)];
    }
    return accept_table[state];
}

/*
    Returns whether the state with given name exists in DFA.
*/
bool DFA::is_valid_state(string name) {
    return state_set.find(name) != state_set.end();
}

/*
    Returns whether the symbol is of DFA.
*/
bool DFA::is_valid_symbol(char symbol) {
    return symbol_set.find(symbol) != symbol_set.end();
}
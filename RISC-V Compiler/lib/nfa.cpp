#include "nfa.h"

typedef set<NFA::state>::iterator state_iter;
typedef set<char>::iterator       symbol_iter;
typedef map<pair<NFA::state, char>, set<NFA::state>>::iterator transition_iter;

NFA::NFA(set<state> state_set, set<char> symbol_set, state start_state) {
    this->state_set   = state_set;
    this->symbol_set  = symbol_set;
    this->start_state = start_state;
}

bool NFA::add_state(string name, bool accept) {
    if (!is_valid_state(name)) {
        state_set.insert(state{name, accept});
        name_set.insert(name);
        return true;
    } 
    else return false;
}

bool NFA::add_transition(string start, char symbol, string dest) {
    // check if the state names are valid
    if (!is_valid_state(start) || !is_valid_state(dest))
        return false;
    
    state st_start = get_state(start);
    state st_dest  = get_state(dest);

    pair<state, char> factor = make_pair(st_start, symbol);
    transition_iter it;
    if ((it = transition.find(factor)) != transition.end()) {
        set<state> &st_set = *it;
    }
}

bool NFA::delete_state(string name) {

}

bool NFA::is_accept(string input) {
    set<state> st_current;
    st_current.insert(start_state);
    
    int n = input.length();
    for (int i=0; i<n; i++) {

    }
}

bool NFA::is_valid_state(string name) {
    return name_set.find(name) != name_set.end();
}

NFA::state NFA::get_state(string name) {

}
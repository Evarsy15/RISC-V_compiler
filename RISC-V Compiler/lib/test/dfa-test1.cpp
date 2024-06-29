#include "../dfa.h"
#include "dfa-aux.h"

DFA dfa1(symbol1);

void set_dfa() {
/*
    Following DFA accepts a string finished by 'a'.
*/
    dfa1.add_state("S", false);
    dfa1.add_state("A", true);
    dfa1.add_state("B", false);
    dfa1.set_start_state("S");

    dfa1.add_transition("S", 'a', "A");
    dfa1.add_transition("S", 'b', "B");
    dfa1.add_transition("A", 'a', "A");
    dfa1.add_transition("A", 'b', "B");
    dfa1.add_transition("B", 'a', "A");
    dfa1.add_transition("B", 'b', "B");    
}

bool task1() {
    return dfa1.is_accepted("abbabaaa");
}

bool task2() {
    return dfa1.is_accepted("bbabb");
}

bool task3() {
    return dfa1.is_accepted("");
}

bool task4() {
    return dfa1.is_accepted("abcba");
}

int main() {
    set_dfa();

    if (task1() != true) {
        printf("TASK 1 FAILED\n");
        return 0;
    } else if (task2() != false) {
        printf("TASK 2 FAILED\n");
        return 0;
    } else if (task3() != false) {
        printf("TASK 3 FAILED\n");
        return 0;
    } else if (task4() != false) {
        printf("TASK 4 FAILED\n");
        return 0;
    } else {
        printf("TEST 1 PASSED!\n");
        return 0;
    }
}
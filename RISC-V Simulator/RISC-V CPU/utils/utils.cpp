
#include "utils.h"

int bits_required(int range_max) {
    int ret = 0;
    int x   = range_max - 1;
    
    while (x > 0) {
        x >> 1;
        ret += 1;
    }

    return ret;
}
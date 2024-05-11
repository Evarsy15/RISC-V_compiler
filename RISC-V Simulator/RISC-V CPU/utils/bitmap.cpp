#include <assert.h>
#include "bitmap.h"

bitmap::bitmap(int size) {
    assert(1 <= size && size <= BITMAP_MAX);
    
    this->bitmap_bits = BITMAP_FREE_ALL;
    this->bitmap_mask = bitmap::bitmask_gen(0, size);
    this->bitmap_size = size;
}

/*
    bitmap_set(start, end) :
        sets bits in [start, end) in the bitmap.
*/
void bitmap::bitmap_set(int start, int end) {
    mask_t mask_set = bitmap::bitmask_gen(start, end);
    bitmap_bits |= mask_set;
    bitmap_bits &= bitmap_mask;
}

/*
    bitmap_free(start, end) :
        frees bits in [start, end) in the bitmap.
*/
void bitmap::bitmap_free(int start, int end) {
    assert(start >= 0);
    assert(end <= bitmap_size);
    assert(start <= end);

    mask_t mask_free = bitmap::bitmask_gen(start, end);
    mask_free    = ~mask_free;
    bitmap_bits &= mask_free;
    bitmap_bits &= bitmap_mask;
}

/*
    bitmask_gen(start, end) : 
        generates a bitmask such that
        bits in [start, end) are set and other bits are free.
*/
mask_t bitmap::bitmask_gen(int start, int end) {
    assert(start >= 0);
    assert(end <= BITMAP_MAX);
    assert(start <= end);

    int    width   = end - start;
    mask_t bitmask = BITMAP_SET_ALL;

    bitmask = bitmask >> (BITMAP_MAX - width);
    bitmask = bitmask << start;

    return bitmask;
}
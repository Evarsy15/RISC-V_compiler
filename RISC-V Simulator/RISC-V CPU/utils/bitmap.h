typedef unsigned long long int bitmap_t;
typedef unsigned long long int mask_t;

#define BITMAP_MAX 64
#define BITMAP_FREE_ALL  0ULL
#define BITMAP_SET_ALL  -1ULL

/*
    bitmap : bitmap class
*/
class bitmap {
  public:
    bitmap(int size);
    
    static mask_t bitmask_gen(int start, int end);
    void bitmap_set (int start, int end);
    void bitmap_free(int start, int end);

    bitmap_t get_bitmap_bits() { return bitmap_bits; }
    int      get_bitmap_size() { return bitmap_size; }

  private:
    bitmap_t bitmap_bits;
    mask_t   bitmap_mask;
    int      bitmap_size;
};

#include "common_def.h"
#include <assert.h>

#ifndef BITMAP_H_H_
#define BITMAP_H_H_

typedef struct bitmap_ {
	unsigned char * bitmap;
	int size;
}bitmap;


bitmap create(int size);
void destroy(bitmap bm);

#define index_of_array(index) (index / sizeof(unsigned char) / 8 )
#define index_of_bit(index) (index % (sizeof(unsigned char) * 8))
#define bit_mask(index) (1 << index)

#define is_index(bm, index) (bm.bitmap[index_of_array(index)] & bit_mask(index_of_bit(index)))
#define set_index(bm, index) (bm.bitmap[index_of_array(index)] |= bit_mask(index_of_bit(index)))
#define unset_index(bm, index) (bm.bitmap[index_of_array(index)] &= ~bit_mask(index_of_bit(index)))

#ifdef TEST
void test_bitmap();
#endif // TEST

#endif // BITMAP_H_H_

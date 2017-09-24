#include "commom_def.h"
#include <assert.h>

#ifndef BITMAP_H_H_
#define BITMAP_H_H_

typedef struct bitmap_ {
	unsigned char * bitmap;
	int size;
}bitmap;

bitmap create(int size) {	
	bitmap bm;	
	bm.bitmap = (int *)malloc(size / sizeof(unsigned char) / 8);	
	assert(bm.bitmap != NULL);	

	memset(bm. bitmap, 0, size / sizeof(unsigned char) / 8);
	bm.size = size; 
	return bm; 
}

void destroy(bitmap bm) {
	if (bm.bitmap != NULL) {
		free(bm.bitmap);
		bm.bitmap = NULL;
		bm.size = 0;
	}
}

#define index_of_array(index) (index / sizeof(unsigned char) / 8 )
#define index_of_bit(index) (index % (sizeof(unsigned char) * 8))
#define bit_mask(index) (1 << index)

#define is_index(bm, index) (bm.bitmap[index_of_array(index)] & bit_mask(index_of_bit(index)))
#define set_index(bm, index) (bm.bitmap[index_of_array(index)] |= bit_mask(index_of_bit(index)))
#define unset_index(bm, index) (bm.bitmap[index_of_array(index)] &= ~bit_mask(index_of_bit(index)))

void test_bitmap() {
	bitmap bm = create(10);
	printf(" index_of_array(0) = %d\n", index_of_array(0));
	printf(" index_of_array(19) = %d\n", index_of_array(19));
	printf(" index_of_bit(0) = %d\n", index_of_bit(0));
	printf(" index_of_bit(19) = %d\n", index_of_bit(19));
	printf(" bit_mask(0) = %d\n", bit_mask(0));
	printf(" bit_mask(3) = %d\n", bit_mask(3));

	printf(" is_index(bm, 0) = %d\n", is_index(bm, 0));
	set_index(bm, 1);
	printf(" set_index(bm, 1) = %d\n", is_index(bm, 1));
	printf(" unset_index(bm, 1) = %d\n", unset_index(bm, 1));

	printf(" is_index(bm, 11) = %d\n", is_index(bm, 11));
	set_index(bm, 11);
	printf(" set_index(bm, 11) = %d\n", is_index(bm, 11));
	printf(" unset_index(bm, 11) = %d\n", unset_index(bm, 11));
}

#endif

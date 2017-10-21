#include "bitmap.h"
#include <stdlib.h>
#include <string.h>

bitmap create(int size) {	
	bitmap bm;	
	bm.bitmap = (unsigned char *)malloc(size / sizeof(unsigned char) / 8);	
	assert(bm.bitmap != NULL);	

	memset(bm.bitmap, 0, size / sizeof(unsigned char) / 8);
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

void test_bitmap() {
	bitmap bm = create(10);
	printf(" index_of_array(0) = %lu\n", index_of_array(0));
	printf(" index_of_array(19) = %lu\n", index_of_array(19));
	printf(" index_of_bit(0) = %lu\n", index_of_bit(0));
	printf(" index_of_bit(19) = %lu\n", index_of_bit(19));
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

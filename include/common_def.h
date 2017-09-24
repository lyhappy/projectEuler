#ifndef COMMON_DEF_H_H
#define COMMON_DEF_H_H

typedef int bool;
#define true 1
#define false 0

#define NULL 0

#include <assert.h>
#include <stdio.h>

#define print_test(test_fn) \
	printf("------------ case of %s ------------\n", #test_fn); \
	test_fn(); \
	printf("-------------------------------------------------------\n");

#endif

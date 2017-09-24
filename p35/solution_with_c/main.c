#include "prime_number.h"
#include <stdio.h>

int r_nums[7];

// 测试rotate_num函数
void test_rotate_num();

bool rotate_num(int n) {
	int digit;
	int i = 0;
	int len = 0;
	r_nums[0] = n;
	r_nums[1] = 0;
	r_nums[2] = 0;
	r_nums[3] = 0;
	r_nums[4] = 0;
	r_nums[5] = 0;
	r_nums[6] = 0;

	while(n > 0) {
		digit = n % 10;
		if (digit % 2 == 0 || digit == 5) 
		  return false; // 包含数字2，4，5，6，8，0的数不会是circular prime
		n /= 10;
		i++;
	}
	len = i;

	digit = 1;
	while(--i > 0)
	  digit *= 10;
	
	i = 1;
	while (i < len) {
		r_nums[i] = r_nums[i-1] / 10 + r_nums[i-1] % 10 * digit;
		i++;
	}
	return true;
}

prime_table pt; 
int count = 3;

static void counter(i) {
	int j = 0;
	if (rotate_num(i)) {
		j = 1;
		while (r_nums[j] != 0) {
			if (!is_prime(pt, r_nums[j])) break;
			j++;
		}
		if (r_nums[j] == 0) {
			count++;
			printf("%d\t", i);
		}
	}
}

void count_circular_prime(int r_max) {
	int i = 5;
	for (i = 5; i < r_max; i+=6) {
		if (is_prime(pt, i)) {
			counter(i);
		}
		if (is_prime(pt, i+2)) {
			counter(i+2);
		}
	}
}

int main() {
	// test_bitmap();
	// test_prime_table();
	pt = create_prime_table(1000000);
	count_circular_prime(1000000);
	printf("\ncount: %d\n", count);
}


void test_rotate_num() {
	int i = 0;

	if (rotate_num(3)) {
		printf("case 3 Done! ");
		while (r_nums[i] != 0)
		  printf("%d ", r_nums[i++]);
		printf("\n");
	}

	i = 0;
	if (rotate_num(193)) {
		printf("case 193 Done! ");
		while (r_nums[i] != 0)
		  printf("%d ", r_nums[i++]);
		printf("\n");
	}

	if (!rotate_num(123)) {
		printf("case 123 Done!\n ");
	}

}


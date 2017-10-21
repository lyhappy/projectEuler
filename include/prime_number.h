#include "bitmap.h"

bool is_prime_number(int n) {
	int i = 0;
	if (n <= 3) {
		return n > 1;
	} else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	} else {
		for (i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
}

typedef bitmap prime_table;
/* 生成长度为size的素数表
 * 表使用bitmap存储，素数值对应的bit位索引上的值0，非素数值对应的bit位索引上的值为1 
 */
prime_table create_prime_table(int size) {
	prime_table pt = create(size);
	set_index(pt, 0);
	set_index(pt, 1);

	int prime = 2;
	while (prime * prime <= size) {
		for (int i = prime * 2; i < size; i+=prime) {
			set_index(pt, i);
		}
		for (prime++; prime * prime <= size; prime++) {
			if (!is_index(pt, prime))
			  break;
		}
	}
	return pt;
}

bool is_prime(prime_table pt, int n) {
	return !is_index(pt, n);
}

void destroy_prime_table(prime_table pt) {
	destroy(pt);
}

void test_prime_table() {
	int i = 0;
	prime_table pt = create_prime_table(100);
	while (i < 100) {
		if (is_prime(pt, i)) {
			printf("%d ", i);
		}
		i++;
	}
	destroy_prime_table(pt);
}

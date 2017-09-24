#include "palindromic.h"

void test() {
	print_test(test_ip_binary);
	print_test(test_ip_decimal);
}

int sum(int n) {
	int sum = 25;	// 0, 1, 3, 5, 7, 9 均满足条件，先求和。
	int i = 11;

	for (; i < n; i+=2) { // 偶数不可能满足二进制回文
		if (is_palindromic_decimal(i) && is_palindromic_binary(i)) { // 逻辑短路，不满足十进制回文，不会检验二进制
			sum += i;
			printf("%d ", i);
			assert(sum > 0); 
		}
	}
	return sum;
}


int main() {
#ifdef TEST
	test();
#endif
	printf("answer: %d\n", sum(1000000));
}

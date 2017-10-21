#include "palindromic.h"
#include <stdio.h>

bool is_palindromic_binary(int n) {
	int b1, b2=0;
	b1 = n;
	while (b1 > 0) {
		b2 = (b2 << 1) | (b1 % 2);
		b1 >>= 1;
	}
	return n == b2;
}

void test_ip_binary() {
	positive_case_print(is_palindromic_binary, 1);
	positive_case_print(is_palindromic_binary, 3);
	negative_case_print(is_palindromic_binary, 2);
	positive_case_print(is_palindromic_binary, 0);
}

bool is_palindromic_decimal(int n) {
	int d1, d2=0;
	d1 = n;
	while (d1 > 0) {
		d2 = d2 * 10 + d1 % 10;
		d1 = d1 / 10;
	}
	return n == d2;
}

void test_ip_decimal() {
	positive_case_print(is_palindromic_decimal, 0);
	positive_case_print(is_palindromic_decimal, 2);
	positive_case_print(is_palindromic_decimal, 3);
	negative_case_print(is_palindromic_decimal, 10);
	positive_case_print(is_palindromic_decimal, 131);
	negative_case_print(is_palindromic_decimal, 122);
}

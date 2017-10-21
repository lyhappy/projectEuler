#include "prime_number.h"
#include <stdio.h>
#include <sys/time.h>


static prime_table pt; 

#define is_prime(n) \
	is_prime(pt, n)

#define right_truncate(n) (n / 10)

bool is_interesting_prime(int n);
// int right_truncate(int n);

bool is_interesting_prime(int n) {
	int tmp = n;
	int base = 1;

	if (n < 10) return false;

	while (n > 0) {
		if (!is_prime(n)) return false;
		n = right_truncate(n);
	}

	n = tmp;
	while (base < tmp) {
		if (!is_prime(n)) return false;

		base = base * 10;
		n = tmp % base;
	}
	return true;
}

void test_is_interesting_prime() {
	positive_case_print(is_interesting_prime, 3797);

	negative_case_print(is_interesting_prime, 2);
	negative_case_print(is_interesting_prime, 13);
}

/* 最直接的办法，直接遍历所有数字
*/
void get_all_interesting_prime(int r_max) {
	int i = 5;
	int c = 1;
	int sum = 0;
	for (i = 5; i < r_max; i+=6) {
		if (is_interesting_prime(i)) {
			printf("interesting prime: %d\n", i);
			c++;
			sum += i;
		}
		if (is_interesting_prime(i+2)) {
			printf("interesting prime: %d\n", i+2);
			c++;
			sum += (i + 2);
		}
		if (c == 12) break;
	}
	printf("answer: %d\n", sum);
}
int digit_index[6];
int len = 2;

void next_candidate_indexes() {
	int i = 0;
	if (digit_index[0] == 1) {
		digit_index[0] = 2;
		return;
	}

	digit_index[0] = 1;
	for (i = 1; i < 6; i++) {
		if (digit_index[i] == 0) {
			len++;
		}
		if (digit_index[i] < 4) {
			digit_index[i]++;
			return;
		} else {
			digit_index[i] = 1;
		}
	}
}

/* 尝试生成所有候选数字
*/
void get_all_interesting_prime_2() {
	int lowest_digit[] = {3, 7};
	int highest_digit[] = {2, 3, 5, 7};
	int middle_digit[] = {1, 3, 7, 9};
	int c = 0;
	int i = 0;
	int x = 0;
	int sum = 0;

	digit_index[0] = 1;
	digit_index[1] = 1;
	while(c < 11) {
		x = highest_digit[digit_index[len-1] - 1];
		for (i = 1; i < len - 1; i++) {
			x = x * 10 + middle_digit[digit_index[i] - 1];
		}
		x = x * 10 + lowest_digit[digit_index[0] - 1];
#ifdef DEBUG
		printf("%d ", x);
#endif

		if (is_interesting_prime(x)) {
			c++;
			sum += x;
			printf("interesting prime: %d count: %d\n", x, c);
		}
		next_candidate_indexes();
	}
	printf("answer: %d\n", sum);

}

void sum_all_interesing_prime();

int main() {
	// clock_t cstart = clock();
	struct timeval cstart, cend;

	pt = create_prime_table(1000000);
#ifdef TEST 
	print_test(test_is_interesting_prime);
#endif
	// cstart = clock();
	gettimeofday(&cstart, NULL);	
	get_all_interesting_prime(1000000);
	gettimeofday(&cend, NULL);	
	printf("%ld cps microsecond\n", (cend.tv_sec - cstart.tv_sec) * 1000000 + cend.tv_usec - cstart.tv_usec);
	// printf ("%.3f cpu sec\n", ((double)clock() - (double)cstart)* 1.0e-6);

	// cstart = clock();
	gettimeofday(&cstart, NULL);	
	get_all_interesting_prime_2();
	gettimeofday(&cend, NULL);	
	printf("%ld cps microsecond\n", (cend.tv_sec - cstart.tv_sec) * 1000000 + cend.tv_usec - cstart.tv_usec);
	// printf ("%.3f cpu sec\n", ((double)clock() - (double)cstart)* 1.0e-6);

	// cstart = clock();
	gettimeofday(&cstart, NULL);	
	sum_all_interesing_prime();
	gettimeofday(&cend, NULL);	
	printf("%ld cps microsecond\n", (cend.tv_sec - cstart.tv_sec) * 1000000 + cend.tv_usec - cstart.tv_usec);
	// printf ("%.3f cpu sec\n", ((double)clock() - (double)cstart)* 1.0e-6);
}


// this is ugly!
void sum_all_interesing_prime() {
	int c = 0;	// counter for interesting prime
	int sum = 0;
	int i, j, k, l, m, o, x;
	int candidate_digits[] = {2, 5, 1, 9, 3, 7};

	for (i = 0; i < 6; i++) {
		x = candidate_digits[i] * 10;
		for (k = 4; k < 6; k++) {
			x = (x + candidate_digits[k]);
			if (is_interesting_prime(x)) {
				c++;
				sum += x;
				printf("interesting prime: %d count: %d\n", x, c);
			}
			x = x - candidate_digits[k];
		}
	}

	for (i = 0; i < 6; i++) {
		x = candidate_digits[i] * 10;
		for (j = 2; j < 6; j++) {
			x = (x + candidate_digits[j]) * 10;
			for (k = 4; k < 6; k++) {
				x = (x + candidate_digits[k]);
				if (is_interesting_prime(x)) {
					c++;
					sum += x;
					printf("interesting prime: %d count: %d\n", x, c);
				}
				x = x - candidate_digits[k];
			}
			x = x / 10 - candidate_digits[j];
		}
	}

	for (i = 0; i < 6; i++) {
		x = candidate_digits[i] * 10;
		for (j = 2; j < 6; j++) {
			x = (x + candidate_digits[j]) * 10;
			for (l = 2; l < 6; l++) {
				x = (x + candidate_digits[l]) * 10;
				for (k = 4; k < 6; k++) {
					x = (x + candidate_digits[k]);
					if (is_interesting_prime(x)) {
						c++;
						sum += x;
						printf("interesting prime: %d count: %d\n", x, c);
					}
					x = x - candidate_digits[k];
				}
				x = x / 10 - candidate_digits[l];
			}
			x = x / 10 - candidate_digits[j];
		}
	}

	for (i = 0; i < 6; i++) {
		x = candidate_digits[i] * 10;
		for (j = 2; j < 6; j++) {
			x = (x + candidate_digits[j]) * 10;
			for (l = 2; l < 6; l++) {
				x = (x + candidate_digits[l]) * 10;
				for (m = 2; m < 6; m++) {
					x = (x + candidate_digits[m]) * 10;
					for (o = 2; o < 6; o++) {
						x = (x + candidate_digits[o]) * 10;
						for (k = 4; k < 6; k++) {
							x = (x + candidate_digits[k]);
							if (is_interesting_prime(x)) {
								c++;
								sum += x;
								printf("interesting prime: %d count: %d\n", x, c);
							}
							x = x - candidate_digits[k];
						}
						x = x / 10 - candidate_digits[o];
					}
					x = x / 10 - candidate_digits[m];
				}
				x = x / 10 - candidate_digits[l];
			}
			x = x / 10 - candidate_digits[j];
		}
	}

}


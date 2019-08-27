#include "prime_number.h"
#include <stdio.h>

#define set_max(n) \
    do { \
        if (n > max) { \
            max =n; \
        } \
    } while (0);

int max = 0;
int visited[9] = {};

int conver_array_to_num(int nums[], size_t n) {
    int num = 0;
    int i = 0;
    int p = 1;
    while (i < n) {
        num += nums[i++] * p;
        p *= 10;
    }
    return num;
}

void dfs(int nums[], size_t n, int * out,  int count) {
    if (count == n) {
        int num = conver_array_to_num(out, n);
        if (true == is_prime_number(num)) {
            set_max(num);
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            out[count] = nums[i];
            dfs(nums, n, out, count + 1);
            visited[i] = 0;
        }
    }
}

void test_catn() {
    int nums[] = {1,2,3};
    printf("%d\n", conver_array_to_num(nums, sizeof(nums)/sizeof(nums[0])));
}

int main(int argc, char** argv) {
    int nums[] = {1,2,3,4,5,6,7,8,9};
    int out[10] = {};
    // test_catn();
    int n = 9;
    while (n > 0)
        dfs(nums, n--, out, 0);
    printf("ans: %d\n", max);
    return 0;
};

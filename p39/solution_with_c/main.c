#include <stdio.h>

#ifdef TEST
#define TEST_PRINT(n) \
    printf("%d: %d\n", n, get_rat_nums_by_perimeter(n));
#else
#define TEST_PRINT(n) \
    do {} while(0)
#endif

/*
 * 检查给定三边长度，是否一个直角三角形
 */
static inline int is_rat(int a, int b, int c) {
    return c * c == a * a + b * b;
}

/*
 * 给定周长，计算可形成的直角三角形个数
 *
 */
int get_rat_nums_by_perimeter(int p) {
    int a = 1, b = 0, c = 0, count = 0;
    while (a < p/3) {
        b = (p - a) / 2;
        c = p - a - b;
        while (b + a > c) {
            is_rat(a, b, c) && count++;
            b--;
            c = p - a - b;
        }
        a++;
    }
    return count;
}

void test() {
    TEST_PRINT(12);
    TEST_PRINT(120);
    TEST_PRINT(840);
    TEST_PRINT(840000);
}

int main(int argc, char** argv) {
    int p = 1000, c = 0, max = 0, max_p = 1000;
    test();
    while(p-- >= 12) {
        c = get_rat_nums_by_perimeter(p);
        if (c > max) {
            max = c;
            max_p = p;
        }
    }
    printf("ans: %d\n", max_p);
    return 0;
};

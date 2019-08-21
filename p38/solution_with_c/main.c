#include <stdio.h>
#include <string.h>

int is_pandigital(int num) {
    if (num > 987654321) {
        return 0;
    }
    int digit_map = 0;
    while (num > 0) {
        digit_map |= (1 << (num % 10));
        num = num / 10;
    }
    return !(digit_map ^ 0x03FE);
}

#ifdef TEST
#define TEST_PRINT(n) \
    printf("%d: %d\n", n, is_pandigital(n));
#else
#define TEST_PRINT(n) \
    do {} while(0)
#endif

void test() {
    TEST_PRINT(123456789);
    TEST_PRINT(123456789);
    TEST_PRINT(987654321);
    TEST_PRINT(932718654);
    TEST_PRINT(1234567890);
    TEST_PRINT(1234567898);
    TEST_PRINT(123456788);
    TEST_PRINT(12345678);
    TEST_PRINT(1234);
}

int main(int argc, char** argv) {
    int num = 9876;

    test();

    while (num-- > 0) {
        if (is_pandigital(num * 100000 + num * 2)) {
            printf ("ans: %d\n", num);
            return 0;
        }
    }
    return -1;
}


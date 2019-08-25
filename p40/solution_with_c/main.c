#include <stdio.h>
#include <string.h>

int get_digits_of_d(int d, int dp[10]) {
    int i = 9, j = 0;
    memset(dp, 0, 10);
    while(d > 0) {
        dp[i--] = d % 10;
        d = d / 10;
    }
    i++;
    while(i <= 9) {
        dp[j++] = dp[i++];
    }
    return j;
}

int main(int argc, char** argv) {
    int d = 1;
    int p = 0;
    int digits[10];
    int dn = 1;
    int product = 1;
    memset(digits, 0, 10);
    while (p <= 1000000) {
        printf("d: %d\t", d);
        int l = get_digits_of_d(d++, digits);
        if (p + l >= dn) {
            product *= digits[dn - p - 1];
            dn = dn * 10;
        }
        p += l;
        printf("p: %d\n", p);
    }
    printf("ans: %d\n", product);
    return 0;
};

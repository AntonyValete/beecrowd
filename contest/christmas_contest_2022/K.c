#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    int rounds, dimension;
    unsigned long long int subgrade, subgrade_rst;

    scanf("%d", &rounds);

    while (i++ < rounds) {
        scanf("%d", &dimension);

        subgrade = dimension * dimension;
        subgrade_rst = (subgrade * (subgrade + 1) / 2) * subgrade;

        printf("%llu\n", subgrade_rst);
    }

    return 0;
}
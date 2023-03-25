#include <stdio.h>

#define ABS(X) ((X) < 0 ? ((~(X)) + 1) : (X))

int main() {
    long long int hashmat, opponent;
    long long int difference;

    while (scanf("%lld %lld", &hashmat, &opponent) != EOF) {
        difference = ABS(hashmat - opponent);

        printf("%lld\n", difference);
    }

    return 0;
}
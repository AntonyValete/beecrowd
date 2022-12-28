#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long int P;
    long long int N;

    scanf("%lld", &P);
    scanf("%lld", &N);

    if (P < N)
        printf("Ainda faltam %llu presentes!\n", (long long int) fabs(N - fabs(P)));
    else
        printf("Sobraram %llu presentes!\n", fabs(P % N));
    return 0;
}
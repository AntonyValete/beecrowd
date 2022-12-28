#include <stdio.h>

#define SQRT3 1.73205080757

int main() {
    int triangleSide;
    double flakArea;

    while(scanf("%d", &triangleSide) != EOF) {
        flakArea = 2.0 * triangleSide * triangleSide * SQRT3 / 5;
        printf("%.2lf\n", flakArea);
    }

    return 0;
}
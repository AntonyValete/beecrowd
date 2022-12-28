#include <stdio.h>

int main() {
    float a, b;
    double media;

    scanf("%f %f", &a, &b);

    media = ((a * 3.5) + (b * 7.5)) / 11;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}
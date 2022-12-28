#include <stdio.h>

int main() {
    char nome[12];
    double salario_fixo, montante, total;

    scanf("%s", nome);
    scanf("%lf %lf", &salario_fixo, &montante);

    total = salario_fixo + (montante * 0.15);

    printf("TOTAL = R$ %.2lf\n", total);

    return 0;
}
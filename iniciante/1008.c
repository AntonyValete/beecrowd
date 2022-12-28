#include <stdio.h>

int main() {
    int numero, horas_trabalhadas;
    float valor_hora, salario;

    scanf("%d %d", &numero, &horas_trabalhadas);
    scanf("%f", &valor_hora);

    salario = horas_trabalhadas * valor_hora;

    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
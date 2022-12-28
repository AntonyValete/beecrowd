#include <stdio.h>
#include <math.h>

#define PI 3.141592654

int main(){
    double a, b, c, qtd_cordao;
    FILE *input = fopen(".\\input.txt", "r");
    FILE *output = fopen(".\\output.txt", "w");

    while (fscanf(input, "%lf %lf %lf", &a, &b, &c) != EOF) {
        qtd_cordao = 5 * ((tan(a * (PI/180)) * b) + c);
        fprintf(output, "%.2lf\n", qtd_cordao);
    }

    return 0;
}
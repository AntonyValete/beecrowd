#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rena {
    char nome[101];
    int peso;
    int idade;
    float altura;
} rena;

int compararRenas(const void *a_pointer, const void *b_pointer);

int main() {
    int qtd_casos, qtd_renas, qtd_renas_puxar, i = 0;

    scanf("%d", &qtd_casos);

    while (i < qtd_casos) {
        scanf("%d %d", &qtd_renas, &qtd_renas_puxar);
        rena *renas = (rena *) malloc(qtd_renas * sizeof(rena));
        
        for (int i = 0; i < qtd_renas; i++) {
            scanf("%s", renas[i].nome);
            scanf("%d", &renas[i].peso);
            scanf("%d", &renas[i].idade);
            scanf("%f", &renas[i].altura);
        }

        qsort(renas, qtd_renas, sizeof(rena), compararRenas);

        printf("CENARIO {%d}\n", i + 1);
        for (int i = 0; i < qtd_renas_puxar; i++) {
            printf("%d - %s\n", i + 1, renas[i].nome);
        }

        free (renas);
        i++;
    }
    return 0;
}

int compararRenas(const void *a_pointer, const void *b_pointer) {
    const rena a = *(rena *)a_pointer;
    const rena b = *(rena *)b_pointer;

    if (!(a.peso == b.peso))
        return b.peso - a.peso;
    if (!(a.idade == b.idade))
        return a.idade - b.idade;
    if (!(a.altura == b.altura))
        return (a.altura > b.altura) ? 1 : -1;
    return !strncmp(a.nome, b.nome, 100);
}
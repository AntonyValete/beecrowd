#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_BUFFER 30

typedef struct ornament {
    char *name;
    int price;
    int acceptance;
} ornament;

int compare(const void *a_ptr, const void *b_ptr);
void output(ornament *ornaments, int budget);

int main() {
    ornament *aux;
    char str[MAX_STR_BUFFER];
    int num_ornaments, budget;
    int i, str_length;

    scanf("%d %d", &num_ornaments, &budget);

    ornament *ornaments = (ornament *) malloc(num_ornaments * sizeof(ornament));

    for (i = 0; i < num_ornaments; i++) {
        aux = &ornaments[i];

        scanf("%s", str);
        str_length = strlen(str);
        aux->name = (char *) malloc((str_length + 1) * sizeof(char));
        strncpy(aux->name, str, str_length + 1);
        aux->name[str_length] = '\0';

        scanf("%d %d", &aux->price, &aux->acceptance);
    }

    qsort(ornaments, num_ornaments, sizeof(ornament), compare);

    output(ornaments, budget);

    return 0;
}

int compare(const void *a_ptr, const void *b_ptr) {
    const ornament a = *(ornament *) a_ptr;
    const ornament b = *(ornament *) b_ptr;

    if (a.price == b.price)
        return b.acceptance - a.acceptance;
    return a.price - b.price;
}

void output(ornament *ornaments, int budget) {
    int i = 0, spent_budget = 0;
    ornament *aux;

    while (spent_budget < budget) {
        aux = &ornaments[i++];

        if (spent_budget + aux->price > budget)
            break;

        puts(aux->name);
        free(aux->name);

        spent_budget += aux->price;
    }
    free(ornaments);
}
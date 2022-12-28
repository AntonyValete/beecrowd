#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRASH_BUFFER 40
#define MAX_STR_BUFFER 15

void readStrings(char ***strings_ptr, int ini, int size);
int compare(const void *a, const void *b);
void freePointers(char **strings_ptr, int size);

int main() {
    char **ingredients;
    char **aux;
    int i; 
    int qtd_pastry_ingredients, qtd_filling_ingredients;
    int new_qtd;


    scanf("%d", &qtd_pastry_ingredients);
    ingredients = (char **) malloc(qtd_pastry_ingredients * sizeof(char *));
    readStrings(&ingredients, 0, qtd_pastry_ingredients);

    scanf("%d", &qtd_filling_ingredients);
    new_qtd = qtd_pastry_ingredients + qtd_filling_ingredients;
    aux = (char **) malloc(new_qtd * sizeof(char *));

    for (i = 0; i < qtd_pastry_ingredients; i++)
        aux[i] = ingredients[i];
    free(ingredients);

    readStrings(&aux, qtd_pastry_ingredients, new_qtd);

    ingredients = aux;

    qsort(ingredients, new_qtd, sizeof(char *), compare);

    for (i = 0; i < new_qtd; i++) {
        while (i < new_qtd - 1 && !strncmp(ingredients[i], ingredients[i + 1], MAX_STR_BUFFER)) {
            i++;
        }
        puts(ingredients[i]);
    }

    freePointers(ingredients, new_qtd);

    return 0;
}

void readStrings(char ***strings_ptr, int ini, int size) {
    char trash_buffer[MAX_TRASH_BUFFER];
    char str_template[MAX_STR_BUFFER];
    int i = ini, length;

    for (; i < size; i++) {
        scanf("%s", str_template);

        length = strlen(str_template);
        (*strings_ptr)[i] = (char *) malloc((length + 1) * sizeof(char));
        strncpy((*strings_ptr)[i], str_template, length + 1);
        ((*strings_ptr)[i])[length] = '\0';

        fgets(trash_buffer, MAX_TRASH_BUFFER, stdin);
    }
}

int compare(const void *a, const void *b) {
    const char *a_ptr = *(const char **)a;
    const char *b_ptr = *(const char **)b;

    return strncmp(a_ptr, b_ptr, MAX_STR_BUFFER);
}

void freePointers(char **strings_ptr, int size) {
    for (int i = 0; i < size; i++) {
        free(strings_ptr[i]);
    }
    free(strings_ptr);
}
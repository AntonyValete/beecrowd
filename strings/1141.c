#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

char ** readStrings(int qtdStrings);
void freeStrings(char **strings, int qtdStrings);
void swapStrings(char **strA, char **strB);
int partition(char **arr, int low, int high);
void quickSort(char **arr, int low, int high);

int main() {
    int qtdStrings, i, j, indexAux, tamStr, tamAux, max, count;
    char **strings;

    while (1) {
        scanf("%d", &qtdStrings);

        if (qtdStrings == 0)
            break;

        max = -1;

        strings = readStrings(qtdStrings);

        quickSort(strings, 0, qtdStrings - 1);

        for (i = 0; i < qtdStrings; i++) {
            tamStr = (int) strlen(strings[i]);
            count = 1;
            indexAux = i;
            for (j = i + 1; j < qtdStrings; j++) {
                tamAux = (int) strlen(strings[j]);
                if (tamStr < tamAux && strstr(strings[j], strings[indexAux]) != NULL) {
                    tamStr = tamAux;
                    indexAux = j;
                    count++;
                }
            }
            if (count > max)
                max = count;
        }

        printf("%d\n", max);

        freeStrings(strings, qtdStrings);
    }


    return 0;
}

char ** readStrings(int qtdStrings) {
    char **strings = (char **) malloc(qtdStrings*sizeof(char *));
    char str[MAX];
    int tam;

    for (int i = 0; i < qtdStrings; i++) {
        scanf("%s", str);
        tam = (int) strlen(str);
        strings[i] = (char *) malloc((tam + 1)*sizeof(char));
        strncpy(strings[i], str, tam);
        strings[i][tam] = '\0';
    }

    return strings;
}

void freeStrings(char **strings, int qtdStrings) {
    for (int i = 0; i < qtdStrings; i++) {
        free(strings[i]);
    }
    free(strings);
}

void swapStrings(char **strA, char **strB) {
    char *aux = *strA;
    *strA = *strB;
    *strB = aux;
}

int partition(char **arr, int low, int high) {
    int pivot = (int) strlen(arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((int) strlen(arr[j]) < pivot) {
            i++;
            swapStrings(&arr[i], &arr[j]);
        }
    }

    swapStrings(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
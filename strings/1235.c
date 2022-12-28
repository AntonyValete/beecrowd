#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 102

int main() {
    int n_cases, tam, parInpar;
    char str[MAX], *str_p = NULL;

    scanf("%d", &n_cases); getchar();

    for (int i = 0; i < n_cases; i++) {
        fgets(str, MAX, stdin);
        str[strlen(str) - 1] = '\0';
        tam = strlen(str);

        parInpar = (tam % 2 == 0) ? 0 : 1;

        str_p = str + ((tam - 1) / 2) - parInpar;
        while (str_p >= str) {
            putchar(*(str_p--));
        }

        str_p = str + tam - 1;
        while (str_p > str + ((tam - 1) / 2) - parInpar) {
            putchar(*(str_p--));
        }
        putchar('\n');
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void printfRest(int index, char *str);

int main() {
    int n_cases, i, diff;
    char str1[MAX], str2[MAX];

    scanf("%d", &n_cases);
    while (n_cases--) {
        scanf("%s %s", str1, str2);

        for (i = 0; str1[i] && str2[i]; i++) {
            printf("%c%c", str1[i], str2[i]);
        }

        diff = strlen(str1) - strlen(str2);

        if (diff > 0)
            printfRest(i, str1);
        else if (diff < 0)
            printfRest(i, str2);

        putchar('\n');
    }

    return 0;
}

void printfRest(int index, char *str) {
    while (str[index] != '\0')
        putchar(str[index++]);
}
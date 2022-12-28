#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char aux[11];
    int number;

    while (1) {
        scanf("%s", aux);

        if (!strcmp(aux, "-1"))
            break;

        if (aux[1] == 'x') {
            number = strtol(aux, NULL, 16);
            printf("%d\n", number);
        } else {
            number = atoi(aux);
            printf("0x%X\n", number);
        }
    }

    return 0;
}
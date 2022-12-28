#include <stdio.h>
#include <stdlib.h>

void printfCase(int case_number, char *number, char base);
void decToBinary(int n);

int main() {
    int n;
    char number[50], base[4];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", number);
        scanf("%s", base);

        printfCase(i+1, number, base[0]);
    }

    return 0;
}

void printfCase(int case_number, char *number, char base) {
    int aux;

    printf("Case %d:\n", case_number);
    switch (base) {
        case 'b':
            aux = (int) strtol(number, NULL, 2);

            printf("%d dec\n", aux);
            printf("%x hex\n", aux);

            break;
        case 'd':
            aux = (int) strtol(number, NULL, 10);

            printf("%x hex\n", aux);
            decToBinary(aux);
            printf(" bin\n");

            break;
        default:
            aux = (int) strtol(number, NULL, 16);

            printf("%d dec\n", aux);
            decToBinary(aux);
            printf(" bin\n");
    }
    printf("\n");
}

void decToBinary(int n) {
    int i;
    for (i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            printf("1");
            i--;
            break;
        }
    }
    for (; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
              printf("1");
        else printf("0");
    }
}
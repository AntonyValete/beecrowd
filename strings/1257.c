#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTER_A 'A'
#define MAX_STR_BUFFER 50

int hash_function(const char *str, int e);

int main() {
    int num_cases, num_lines;
    int hash_acumulator;
    char str[MAX_STR_BUFFER + 1];

    scanf("%d", &num_cases);

    while (num_cases--) {
        hash_acumulator = 0;
        scanf("%d", &num_lines);
        for (int i = 0; i < num_lines; i++) {
            scanf("%s", str);
            hash_acumulator += hash_function(str, i);
        }
        printf("%d\n",)
    }
    return 0;
}

int hash_function(const char *str, int e) {
    int sum = 0;

    for (int i = 0; i < strlen(str); i++) {
        sum += (str[i] - LETTER_A) + e + i;
    }

    return sum;
}
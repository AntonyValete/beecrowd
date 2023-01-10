#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_BUFFER 200
#define ALPHABET_SIZE 26
#define LETTER_A 'a'

typedef struct string {
    size_t size;
    char buff[MAX_STR_BUFFER + 1];
} string;

int * def_frequence(string *case_aux);
int max_frequence(int *alphabet);

int main() {
    int num_cases, max_letter_frequence;
    string case_aux;

    scanf("%d", &num_cases); getchar();
    while (num_cases--) {
        fgets(case_aux.buff, MAX_STR_BUFFER + 1, stdin);
        case_aux.size = strlen(case_aux.buff) - 1;
        case_aux.buff[case_aux.size] = '\0';

        int *alphabet_frequence = def_frequence(&case_aux);

        max_letter_frequence = max_frequence(alphabet_frequence);

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (max_letter_frequence == alphabet_frequence[i])
                putchar(i + LETTER_A);
        }
        putchar('\n');
        free(alphabet_frequence);
    }
    return 0;
}

int * def_frequence(string *case_aux) {
    int *aux = (int *) calloc(ALPHABET_SIZE, sizeof(int));
    char c;

    for (int i = 0; i < case_aux->size; i++) {
        c = tolower(case_aux->buff[i]);

        if (c >= 97 && c <= 122)
            aux[c - LETTER_A]++;
    }

    return aux;
}

int max_frequence(int *alphabet) {
    int max = alphabet[0];

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (max < alphabet[i])
            max = alphabet[i];
    }

    return max;
}
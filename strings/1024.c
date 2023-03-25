#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void convertLetters(const char *str, char *strToChange, int length);
void invertStr(char *strToChange, int length);
void convertHalfStr(char *strToChange, int length);
void swap(char *a, char *b);

int main() {
    int n, length;
    char str[MAX], *strConverted;

    scanf("%d", &n); getchar();
    for (int i = 0; i < n; i++) {
        fgets(str, MAX, stdin);
        str[strlen(str) - 1] = '\0';
        length = strlen(str);
        strConverted = (char *) malloc((strlen(str) + 1)*sizeof(char));

        convertLetters(str, strConverted, length);
        invertStr(strConverted, length);
        convertHalfStr(strConverted, length);

        printf("%s\n", strConverted);
        free(strConverted);
    }

    return 0;
}

void convertLetters(const char *str, char *strToChange, int length) {
    for (int i = 0; i < length; i++) {
        if (((int) str[i] >= 65 && (int) str[i] <= 90) || ((int) str[i] >= 97 && (int) str[i] <= 122))
            strToChange[i] = (char) (((int) str[i]) + 3);
        else 
            strToChange[i] = str[i];
    }
    strToChange[length] = '\0';    
}

void invertStr(char *strToChange, int length) {
    for (int i = 0; i < length/2; i++) {
        swap(&strToChange[i], &strToChange[length - i - 1]);
    }
}

void convertHalfStr(char *strToChange, int length) {
    for (int i = length/2; i < length; i++) {
        strToChange[i] = (char) ((int) strToChange[i] - 1);
    }
}

void swap(char *a, char *b) {
    char aux = *a;
    *a = *b;
    *b = aux;
}
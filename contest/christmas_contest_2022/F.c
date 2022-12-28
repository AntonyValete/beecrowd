#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_BUFFER 1000
#define BLUE_BUFFER 4
#define AZUL_BUFFER 4
#define RED_BUFFER 3
#define VERMELHO_BUFFER 8

const char *blue = "blue";
const char *azul = "azul";
const char *red = "red";
const char *vermelho = "vermelho";

int countWords(char *str, int str_length);
int countCharacters(char *str, int startPoint);
char ** separeteWords(char *str, int num_words, int str_length);
void output(char **strArr, int num_words);

int main() {
    char string[MAX_STR_BUFFER + 2];
    char **words;
    int length, i, num_words;

    fgets(string, MAX_STR_BUFFER + 1, stdin);
    length = strlen(string) - 1;
    string[length] = '\0';

    num_words = countWords(string, length);

    words = separeteWords(string, num_words, length);

    for (i = 0; i < num_words; i++) {
        if (!strncmp(words[i], blue, BLUE_BUFFER + 1)) {
            free(words[i]);
            words[i] = (char *) malloc((AZUL_BUFFER + 1) * sizeof(char));
            strncpy(words[i], azul, AZUL_BUFFER);
            words[i][AZUL_BUFFER] = '\0';
        }
        else if (!strncmp(words[i], red, RED_BUFFER + 1)) {
            free(words[i]);
            words[i] = (char *) malloc((VERMELHO_BUFFER + 1) * sizeof(char));
            strncpy(words[i], vermelho, VERMELHO_BUFFER);
            words[i][VERMELHO_BUFFER] = '\0';
        }
    }

    output(words, num_words);

    return 0;
}

int countWords(char *str, int str_length) {
    int num_of_words = 0;
    
    for (int i = 0; i <= str_length; i++) {
        if (str[i] == ' ' || str[i] == '\0')
            num_of_words++;
    }

    return num_of_words;
}

int countCharacters(char *str, int startPoint) {
    int aux = 0;

    while (str[startPoint + aux] != ' ' && str[startPoint + aux] != '\0')
        aux++;

    return aux;
}

char ** separeteWords(char *str, int num_words, int str_length) {
    int i, str_buffer_size, word = 0;
    char **auxArr = (char **) malloc(num_words * sizeof(char *));

    for (i = 0; i < str_length; i++) {
        str_buffer_size = countCharacters(str, i);

        auxArr[word] = (char *) malloc((str_buffer_size + 1) * sizeof(char));
        strncpy(auxArr[word], (str + i), str_buffer_size);
        auxArr[word][str_buffer_size] = '\0';
        
        i += str_buffer_size;
        word++;
    }

    return auxArr;
}

void output(char **strArr, int num_words) {
    int i;
    
    for (i = 0; i < num_words - 1; i++) {
        printf("%s ", strArr[i]);
        free(strArr[i]);
    }
    puts(strArr[i]);
    free(strArr[i]);
}
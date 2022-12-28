#include <stdio.h>

int main(){
    int hI, hF, mI, mF, I, F, h, m;

    scanf("%d %d %d %d", &hI, &mI, &hF, &mF);

    I = (hI * 60) + mI;
    F = (hF * 60) + mF;

    if (I > F){
        h = (1440 - I + F)/60;
        m = (1440 - I + F)%60;
    }
    else if (I < F){
        h = (F - I)/60;
        m = (F - I)%60;
    }
    else {
        h = 24;
        m = 0;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
}
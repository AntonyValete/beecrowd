    #include <stdio.h>
    #include <stdlib.h>
    
    int main(){

        int tI, tF;

        scanf("%d %d", &tI, &tF);
        
        if (tI < 24){
            
            tI = 24 - tI; 
            printf("O JOGO DUROU %d HORA (S)", tI + tF);
        }
        else{

            if (tI == tF){

                printf("O JOGO DUROU 24 HORA (S)");
            }
            else{

                printf("O JOGO DUROU %d HORA (S)", tF - tI);
            }
        }
        return 0;
    }
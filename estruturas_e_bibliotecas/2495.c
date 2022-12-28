#include <stdio.h>

int main() {
    int n, sum, aux;
    
    while (scanf("%d", &n) != EOF) {
        sum = (n * (n + 1)) / 2;
        
        for (int i = 0; i < n - 1; i++) {
            scanf("%d", &aux);
            sum -= aux;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}
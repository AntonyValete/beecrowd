var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

function prime() {
    let primeCount;
    let prime;
    for (let i = 1; primeCount <= n; i++) {
        prime = 0;
        for (i2 = 1; i2 <= i / 2; i2++) {
            if (i % i2 == 0) {
                prime++;
                if (prime > 1)
                    break;
            }
        }
        if (prime == 1) {
            printf("%d\n", i);
            primeCount++;
        }
    }
}
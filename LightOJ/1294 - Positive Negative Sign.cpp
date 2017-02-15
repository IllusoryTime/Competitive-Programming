//Source Code Written: 3/11/15

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

int main() {
    int caseno = 0, cases;
    long long int n, m;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lld %lld", &n, &m);
        long long int d = (m*n)/2;
        printf("Case %d: %lld\n", ++caseno, d);
    }
    return 0;
}

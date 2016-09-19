//Source Code Written: 3/19/15

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, caseno = 0, cases;
    long long int a, b, c;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if((a*a + b*b) == c*c) printf("Case %d: yes\n", ++caseno);
        else if((a*a + c*c) == b*b) printf("Case %d: yes\n", ++caseno);
        else if((c*c + b*b) == a*a) printf("Case %d: yes\n", ++caseno);
        else printf("Case %d: no\n", ++caseno);
    }
    return 0;
}

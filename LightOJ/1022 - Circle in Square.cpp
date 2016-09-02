//Source Code Written: 1/14/13

#include <stdio.h>
#include <math.h>

int main() {
    int t, tc = 0;
    double r, result;

    scanf("%d", &t);
    while(t--){
        scanf("%lf", &r);
        result = (((2*r)*(2*r)) - ((2*acos(0.0))*(r*r)));
        printf("Case %d: %0.2lf\n", ++tc, result);
    }
    return 0;
}

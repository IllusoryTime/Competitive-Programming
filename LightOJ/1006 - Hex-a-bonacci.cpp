//Source Code Written: 5/21/13

#include <stdio.h>

int a, b, c, d, e, f;
int array[10010];

int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if( array[n]!=-1 ) return array[n];
    else {
        array[n] = (( fn(n-1)%10000007 + fn(n-2)%10000007 + fn(n-3)%10000007 + fn(n-4)%10000007 + fn(n-5)%10000007 + fn(n-6)%10000007 ))%10000007;
        return  array[n];
    }
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        for(int i=1; i<=n; i++) {
            array[i] = -1;
        }
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

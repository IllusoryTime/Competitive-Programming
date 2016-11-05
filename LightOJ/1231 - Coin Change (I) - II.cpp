//Source Code Written: 4/4/15

#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;
const int N = 100;

int cases, caseno, n, K, A[N], C[N], d[1005];

int sum (int a, int b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &K);

        for( int i = 0; i < n; i++ ) scanf("%d", &A[i]);
        for( int i = 0; i < n; i++ ) scanf("%d", &C[i]);

        memset( d, 0, sizeof(d) );
        d[0] = 1;
        for( int i = 0; i < n; i++ ) {
            for( int j = K; j >= 0; j-- ) {
                int s = j;
                for( int k = 0; k < C[i]; k++ ) {
                    s += A[i];
                    if( s > K ) break;
                    d[s] = sum(d[s], d[j]);
                }
            }
        }
        printf("Case %d: %d\n", ++caseno, d[K]);
    }
    return 0;
}

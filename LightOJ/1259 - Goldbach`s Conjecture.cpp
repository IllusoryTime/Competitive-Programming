//Source Code Written: 8/27/15

#include <bits/stdc++.h>
using namespace std;
#define MAX  10000000

bool Check(int N, int pos) {
    return (bool)(N & (1<<pos));
}
int Set(int N, int pos) {
    return N = N | (1<<pos);
}
int status[(MAX>>5) + 2], primes[664580], Nprimes = 0;
void sieve(int N) {
    status[0] = Set(status[0], 0);
    status[0] = Set(status[0], 1);
    for(int i = 4; i <= N; i += 2) status[i>>5] = Set(status[i>>5], i&31);
    int sqrtN, i, j;
    sqrtN = int( sqrt(N) );
    for(i = 3; i <= sqrtN; i += 2)
        if(Check(status[i>>5], i&31) == 0)
            for(j = i*i; j <= N; j += (i<<1))
                status[j>>5] = Set(status[j>>5], j&31);
    primes[Nprimes++] = 2;
    for(int i = 3; i <= N; i += 2)
        if(Check(status[i>>5], i&31) == 0)
            primes[Nprimes++] = i;
}

int main() {
    //freopen("in.txt", "r", stdin);
    sieve(MAX);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++tc);
        int x, cnt = 0;
        scanf("%d", &x);
        for(int i = 0; primes[i] <= x/2; i++)
            if(Check(status[(x-primes[i])>>5], (x-primes[i])&31) == 0)
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}

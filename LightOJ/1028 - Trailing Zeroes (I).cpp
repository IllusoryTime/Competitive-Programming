//Source Code Written: 2/25/16

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int MAX = 2000000, NP = 664579;
int flag[(MAX>>6) + 2], primes[NP], total;

#define on(x) (flag[x>>6] & (1<<((x&63)/2)))
#define mark(x) flag[x>>6] |= (1<<((x&63)/2))

void sieve(int N) {
    for(int i=3; i*i<=N; i+=2) {
        if(!on(i)) {
            for(int j=i*i; j<=N; j+=(i<<1)) {
                mark(j);
            }
        }
    }
    primes[(total=0)++] = 2;
    for(int i=3; i<=N; i+=2)
        if(!on(i))
            primes[total++] = i;
}

int divisor(ULL N) {
    int val = (int)sqrt(N), ans = 1;
    for(int i=0; primes[i]<=val; i++) {
        if(N%primes[i] == 0) {
            int cnt = 0;
            while(N%primes[i] == 0) {
                cnt++;
                N /= primes[i];
            }
            ans *= (cnt+1);
            val = (int)sqrt(N);
        }
    }
    if(N > 1) ans *= 2;
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
    sieve(MAX);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        ULL N;
        scanf("%llu", &N);
        printf("Case %d: %d\n", ++tc, divisor(N)-1);
    }
    return 0;
}

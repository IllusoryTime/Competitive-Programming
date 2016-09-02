//Source Code Written: 2/24/16

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define S 46180

bool flag[MAX+5];
int primes[S+5];

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return flag[n] == false;
}

int sieve(int N) {
    for (int i = 3; i * i <= N; i += 2)
        if (flag[i] == false)
            for (int j = i * i; j <= N; j += i + i)
                flag[j] = true;
    int total = 0;
    for(int i=2; i<=N; i++)
        if(isPrime(i))
            primes[total++]=i;
}


int store_primes[S], freq_primes[S], store_divisor[MAX], total, ans;

void divisor(int N) {
    int val = sqrt(N), cnt;
    total = 0;
    for(int i=0; primes[i]<=val; i++) {
        if(N%primes[i] == 0) {
            cnt = 0;
            while(N%primes[i] == 0) {
                N /= primes[i];
                cnt++;
            }
            store_primes[total] = primes[i];
            freq_primes[total] = cnt;
            total++;
            val = sqrt(N);
        }
    }
    if(N > 1) {
        store_primes[total] = N;
        freq_primes[total] = 1;
        total++;
    }
}

void Generate(int cur, int num) {
    int val;
    if(cur == total) {
        store_divisor[ans++] = num;
    } else {
        val = 1;
        for(int i=0; i<=freq_primes[cur]; i++) {
            Generate(cur+1, num*val);
            val *= store_primes[cur];
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    sieve(MAX);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++tc);
        int P, L;
        scanf("%d%d", &P, &L);
        if(P-L <= L) {
            printf("impossible\n");
            continue;
        }
        divisor(P-L);
        ans = 0;
        Generate(0, 1);
        sort(store_divisor, store_divisor + ans);
        for(int i=0; i<ans; i++)
            if(store_divisor[i] > L)
                printf("%d%c", store_divisor[i], (i==ans-1?'\n':' '));
    }
    return 0;
}

//Source Code Written: 6/19/15

#include<bits/stdc++.h>
using namespace std;

#define SIZE_N 1000000 + 7
#define SIZE_P 100000 + 7
bool flag[SIZE_N];
int primes[SIZE_P];

void seive() {
    int i, j, total = 0, val;
    for(i=2; i<=SIZE_N; i++) flag[i] = 1;
    val = sqrt(SIZE_N) + 1;
    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=SIZE_N; j++)
                flag[i*j] = 0;
    for(i=2; i<=SIZE_N; i++)
        if(flag[i])
            primes[total++] = i;
}

int divisor(int N) {
    int i, val, cnt, sum = 1;
    val = sqrt(N) + 1;
    for(i=0; primes[i]<val; i++) {
        if(N%primes[i] == 0) {
            cnt = 0;
            while(N%primes[i] == 0) {
                N /= primes[i];
                cnt++;
            }
            sum *= (cnt+1);
        }
    }
    if(N>1)
        sum *= 2;
    return sum;
}

int main() {
    //freopen("in.txt", "r", stdin);
    seive();
    int a[86765 + 9], n, t, tc = 0;
    a[0] = 1;
    a[1] = 2;
    for(int i=2; i<1000000; i++) {
        a[i] = a[i-1] + divisor(a[i-1]);
        if(a[i] > 1000000) {
            n = i;
            break;
        }
    }
    scanf("%d", &t);
    while(t--) {
        int A, B;
        scanf("%d %d", &A, &B);
        int l = lower_bound(a, a+n, A) - a;
        int u = upper_bound(a, a+n, B) - a;
        printf("Case %d: %d\n", ++tc, u - l);
    }
    return 0;
}

//Source Code Written: 6/1/15

#include <bits/stdc++.h>
using namespace std;

int prime_num[10000];
typedef long long int LL;

bool is_prime(LL n) {
    LL i, root;
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    if(n % 2 == 0) {
        return 0;
    }
    root = sqrt(n);
    for(i=3; i<=root; i+=2) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int divisor(LL N) {
    int i, val, cnt, sum;
    val = sqrt(N)+1;
    sum = 1;
    for(i=0; prime_num[i]<val; i++) {
        if(N%prime_num[i] == 0) {
            cnt=0;
            while(N%prime_num[i] == 0) {
                N /= prime_num[i];
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
    int total = 0;
    for(int j=1; j<=65536+1; j++) {
        if(is_prime(j)) {
            prime_num[total++] = j;
        }
    }
    LL n;
    while(scanf("%lld",&n)==1) {
        if(n == 0) break;
        if(divisor(n)%2) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

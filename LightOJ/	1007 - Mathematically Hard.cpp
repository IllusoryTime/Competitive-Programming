//Source Code Written: 2/25/16

#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000010;
unsigned long long phi[MAX + 9], x, y;

void euler_phi() {
    phi[1] = 1;
    for(int i=2; i<=MAX; i++) {
        if(!phi[i]) {
            phi[i] = i - 1;
            for(int j=(i<<1); j<=MAX; j+=i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    euler_phi();
    for(int i=2; i<=MAX; i++) phi[i] *= phi[i], phi[i] += phi[i-1];
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%llu%llu", &x, &y);
        printf("Case %d: %llu\n", ++tc, phi[y] - phi[x-1]);
    }
    return 0;
}

//Source Code Written: 5/24/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, ans = 1, array1[15];
    for(int i = 1; i <= 14; i++) {
        ans *= i;
        array1[i] = ans;
    }
    while(scanf("%lld", &n) == 1) {
        if(n < 0) {
            if(-n%2) printf("Overflow!\n");
            else printf("Underflow!\n");
        }
        else if(n < 8 && n >= 0) printf("Underflow!\n");
        else if(n > 13) printf("Overflow!\n");
        else printf("%lld\n", array1[n]);
    }
    return 0;
}

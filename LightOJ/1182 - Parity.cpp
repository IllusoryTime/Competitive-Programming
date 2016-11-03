//Source Code Written: 3/22/15

#include<bits/stdc++.h>
using namespace std;
int main() {
    int test, caseno = 0;
    cin >> test;
    while(test--) {
        long long int n, k = 0;
        cin >> n;
        while(n>0) {
            if(n%2) k++;
            n /= 2;
        }
        if(k%2) printf("Case %d: odd\n", ++caseno);
        else printf("Case %d: even\n", ++caseno);
        k = 0;
    }
    return 0;
}

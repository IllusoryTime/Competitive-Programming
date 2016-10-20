//Source Code Written: 3/22/15

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        long long n, i = 2;
        cin >> n;
        if(n % 2) printf("Case %d: Impossible\n", ++tc);
        else if(n == 2) printf("Case %d: 1 2\n", ++tc);
        else {
            while(!(n % 2)) {
                if((n/2) % 2) {
                    printf("Case %d: %lld %lld\n", ++tc, n/2, i);
                    break;
                } else {
                    n /= 2;
                    i *= 2 ;
                }
            }
        }
    }
    return 0;
}

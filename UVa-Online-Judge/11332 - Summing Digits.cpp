//Source Code Written: 6/3/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    while(cin >> n) {
        if(n == 0) break;
        else if(n%9) printf("%d\n", n%9);
        else printf("9\n");
    }
    return 0;
}

//Problem Solved: 5/19/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    int n, b, k, sum = 0;;
    cin >> n >> b;
    int ans = (n-1)*2;
    for(int i=0; i<n; i++) {
        cin >> k;
        sum += k;
    }
    int tmp = (n-1)*10 + sum;
    b -= tmp;
    if(b < 0) printf("-1\n");
    else {
        ans += (b/5);
        printf("%d\n", ans);
    }
    return 0;
}

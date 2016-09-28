//Problem Solved: 5/19/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, x, ans = 0 , k[100005];
    cin >> n >> x;
    for(int i=0 ; i<n; i++) cin >> k[i];
    sort(k, k+n);
    for(int i=0 ; i<n; i++) {
        ans += k[i] * (x-i>=1 ? x-i : 1);
    }
    cout << ans << endl;
    return 0;
}

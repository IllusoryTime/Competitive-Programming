//Source Code Written: 6/13/15
//Using Recursion

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 35000;
int n, w, p, q, a[35];
LL sum1[N], sum2[N];

void function1(LL sum, int i) {
    if(i == n/2) {
        sum1[p++] = sum;
        return;
    }
    function1(sum, i+1);
    function1(sum+a[i], i+1);
}
void function2(LL sum, int i) {
    if(i == n) {
        sum2[q++] = sum;
        return;
    }
    function2(sum, i+1);
    function2(sum+a[i], i+1);
}

int main() {
    //freopen("in.txt","r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        p = q = 0;
        cin >> n >> w;
        LL ans = pow(2, n);
        for(int i=0; i<n; i++) cin >> a[i];
        function1(0, 0);
        function2(0, n/2);
        sort(sum2, sum2+q);
        for(int i=0; i<p; i++) {
            int k = upper_bound(sum2, sum2+q, w-sum1[i]) - sum2;
            k = q - k;
            ans -= k;
        }
        printf("Case %d: %lld\n", ++tc, ans);
    }
    return 0;
}

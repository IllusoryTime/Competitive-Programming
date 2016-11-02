//Source Code Written: 6/14/15

#include <bits/stdc++.h>
using namespace std;

int zero(int n) {
    int sum = 0;
    while(n) {
        sum += n/5;
        n /= 5;
    }
    return sum;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0, q;
    cin >> t;
    while(t--) {
        printf("Case %d: ", ++tc);
        cin >> q;
        int lo = 5, hi = 1e9, mid;
        while(1) {
            mid = (lo+hi)/2;
            if(lo == hi && zero(mid) != q) {
                printf("impossible\n");
                break;
            }
            int n = zero(mid);
            if(n == q) break;
            else if(n < q) lo = mid + 1;
            else hi = mid;
        }
        if(zero(mid) == q) {
            while(zero(mid) == q) {
                mid--;
            }
            printf("%d\n", mid+1);
        }
    }
    return 0;
}

//Source Code Written: 6/19/15

#include<bits/stdc++.h>
using namespace std;

int a[100000+7];
int main() {
    //freopen("in.txt", "r", stdin);
    int n, y;
    while(scanf("%d", &y) == 1) {
        scanf("%d", &n);
        int ans = 0, pos;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) {
            int l = upper_bound(a+i, a+n, a[i]+y-1) - a;
            if(ans < l-i) {
                ans = l-i;
                pos = i;
            }
        }
        printf("%d %d %d\n", ans, a[pos], a[pos+ans-1]);
    }
    return 0;
}


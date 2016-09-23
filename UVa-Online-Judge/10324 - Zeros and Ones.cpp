//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

char str[1000000 + 7];

bool check(int p, int q) {
    for(int i = p; i < q; i++) {
        if(str[i] != str[i + 1])
            return false;
    }
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int tc = 0, t, x, y;
    while(scanf("%s", str) == 1) {
        printf("Case %d:\n", ++tc);
        cin >> t;
        while(t--) {
            cin >> x >> y;
            int p = min(x, y);
            int q = max(x, y);
            if(check(p, q)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

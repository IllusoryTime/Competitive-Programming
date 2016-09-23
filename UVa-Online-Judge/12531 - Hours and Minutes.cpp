//Source Code Written: 5/24/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    bool mark[180 + 7];
    int ang1, ang2, h, m, ans, ang;
    memset(mark, false, sizeof(mark));
    for(int i=0; i<=720; i++) {
        h = i/12;
        m = i%60;
        ang1 = h * 6;
        ang2 = m * 6;
        ans = abs(ang1 - ang2);
        ans = min(ans, 360-ans);
        mark[ans] = true;
    }
    while(scanf("%d", &ang)==1) {
        if(mark[ang]) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

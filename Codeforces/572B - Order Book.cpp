//Problem Solved: 8/22/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

bool flag1[100000+9], flag2[100000+9];
int main() {
    //freopen("in.txt", "r", stdin);
    memset(flag1, false, sizeof(flag1));
    memset(flag2, false, sizeof(flag2));
    map <int, int> mymapb, mymaps;
    int n, s, k = 0, l = 0, x, a[1000+9], b[1000+9], t, s1, s2;
    char ch;
    scanf("%d %d\n", &n, &s);
    s1 = s2 = s;
    for(int i=1; i<=n; i++) {
        scanf("%c", &ch);
        if(ch == 'B') {
            scanf("%d %d\n", &t, &x);
            if(!flag1[t]) {
                a[k] = t;
                k++;
            }
            mymapb[t] += x;
            flag1[t] = true;
        } else {
            scanf("%d %d\n", &t, &x);
            if(!flag2[t]) {
                b[l] = t;
                l++;
            }
            mymaps[t] += x;
            flag2[t] = true;
        }
    }
    sort(a, a+k);
    sort(b, b+l);
    for(int i=s1-1; i>=0; i--) if(i < l) printf("S %d %d\n", b[i], mymaps[b[i]]);
    for(int i=k-1; s2>0 && i>=0; s2--, i--) printf("B %d %d\n", a[i], mymapb[a[i]]);
    return 0;
}

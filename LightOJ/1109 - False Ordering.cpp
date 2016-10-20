//Source Code Written: 6/4/15

#include <bits/stdc++.h>
using namespace std;

struct Number {
    int n, d;
} num[1000 + 8];

bool cmp (Number A, Number B) {
    if(A.d != B.d) return A.d < B.d;
    else return A.n > B.n;
}

int main() {
    //freopen("in.txt", "r", stdin);
    num[1].d = 1;
    num[1].n = 1;
    for(int i=2; i<=1000; i++) {
        num[i].n = i;
        int count_it = 0;
        for(int j=1; j<=i/2; j++) {
            if(i%j == 0)
                count_it++;
        }
        count_it++;
        num[i].d = count_it;
    }
    sort(num + 1, num + 1001, cmp);
    int t, tc = 0, n;
    cin >> t;
    while(t--) {
        printf("Case %d: ", ++tc);
        cin >> n;
        printf("%d\n", num[n].n);
    }
    return 0;
}

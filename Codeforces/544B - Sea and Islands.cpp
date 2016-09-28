//Problem Solved: 5/7/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int n, k, sum = 0, o = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        if(!(i%2)) sum += (i-1);
        else sum += i;
    }
    if(sum >= k) {
        printf("YES\n");
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(((i%2 && j%2) || (!(i%2) && !(j%2))) && o < k) {
                    printf("L");
                    o++;
                } else printf("S");
            }
            printf("\n");
        }
    } else printf("NO\n");
    return 0;
}

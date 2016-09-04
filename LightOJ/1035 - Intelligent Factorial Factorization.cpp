//Source Code Written: 3/5/15

#include <bits/stdc++.h>

int main() {
    //freopen("in.txt", "r", stdin);
    int test, n, ans;
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    scanf("%d", &test);
    for(int i=1; i<=test; i++) {
        scanf("%d", &n);
        printf("Case %d: %d = ", i, n);
        int k = 0;
        while(p[k] <= n) {
            int h = n; ans = 0;
            while(h > 0) {
                ans += (h/p[k]);
                h = h/p[k];
            }
            if(p[k] != 2) printf(" * ");
            printf("%d (%d)", p[k], ans); k++;
        }
        printf("\n");
    }
    return 0;
}

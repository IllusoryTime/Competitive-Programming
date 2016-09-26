//Problem Solved: 7/27/13
//Last Update: 9/27/16

#include <stdio.h>
int main() {
//    freopen("in.txt", "r", stdin);
    int n, s, c, a[101][101], d[101][101], cnt = 1;
    scanf("%d", &n);
    s = n*n;
    c = n/2;
    for(int i=0; i<c; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = cnt;
            d[i][j] = s+1-cnt;
            cnt++;
        }
    }
    for(int j=0; j<n; j++) {
        for(int i=0; i<c; i++) {
            printf("%d %d ", a[i][j], d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

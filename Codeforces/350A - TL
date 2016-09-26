//Problem Solved: 10/1/13
//Last Edit: 9/27/16

#include <stdio.h>
int main() {
    int a, b, n[101], m[101], k = 101, s = 101, l = 0, p;
    scanf("%d %d", &a, &b);
    for(int i=0; i<a; i++)
        scanf("%d", &n[i]);
    for(int i=0; i<b; i++)
        scanf("%d", &m[i]);
    for(int i=0; i<a; i++) {
        if(k > n[i]) k = n[i];
        if(l < n[i]) l = n[i];
    }
    for(int i=0; i<b; i++) {
        if(s > m[i]) s = m[i];
    }
    p = 2*k;
    if(p < l || p == l) {
        if(l < s) printf("%d\n", l);
        else printf("-1\n");
    }
    else if(p > l && p < s) printf("%d\n", p);
    else printf("-1\n");
    return 0;
}

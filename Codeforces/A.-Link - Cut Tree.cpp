//Problem Solved: 1/15/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.txt", "r", stdin);
    long long l, r, k;
    cin >> l >> r >> k;
    if(k > r && l != 1) {
        puts("-1");
        return 0;
    }
    long long po = 1, flag = 0, last = 1;
    if(l == 1) {
        printf("1");
        flag = 1;
    }
    for(int i=0; i<100000 ; i++) {
        po *= k;
        if(po / k != last) break;
        last *= k;
        if(po > r) break;
        if(po >= l && po <= r) {
            if(flag) printf(" ");
            printf("%I64d", po);
            flag = 1;
        }
    }
    if(!flag) printf("-1");
    printf("\n");
    return 0;
}

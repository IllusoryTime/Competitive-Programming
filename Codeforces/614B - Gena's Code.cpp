//Problem Solved: 1/14/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;
int main() {
    ///freopen("in.txt", "r", stdin);
    int n, cnt = 0, flag = 0, nb = 0;
    char k[100000 + 9], st[100000 + 9];
    scanf("%d\n", &n);
    for(int j=1; j<=n; j++) {
        int cnt1 = 0, cnt0 = 0;
        scanf("%s", k);
        int len = strlen(k);
        if(len == 1 && k[0] == '0') flag = 1;
        for(int i=0; i<len; i++) {
            if(k[i] == '1') cnt1++;
            else if(k[i] == '0') cnt0++;
        }
        if((cnt1 + cnt0) != len || cnt1 > 1) {
            int i;
            for(i=0; i<len; i++) st[i] = k[i];
            st[i] = '\0';
            nb = len;
            cnt -= cnt0;
        }
        cnt += cnt0;
    }
    if(flag == 1) printf("0");
    else {
        if(nb != 0) {
            for(int i=0; i<nb; i++) printf("%c", st[i]);
            for(int i=0; i<cnt; i++) printf("0");
        } else {
            printf("1");
            for(int i=0; i<cnt; i++) printf("0");
        }
    }
    printf("\n");
    return 0;
}

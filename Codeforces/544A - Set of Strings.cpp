//Problem Solved: 5/7/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    char s[102];
    int ck[267], k, q = 0, z = 0;
    memset(ck, 0, sizeof(ck));
    cin >> k >> s;
    int len = strlen(s);
    if(len < k) printf("NO\n");
    else {
        for(int i=0 ; i<len; i++) {
            if(ck[s[i]] == 0) {
                q++;
                ck[s[i]]++;
            }
        }
        memset(ck, 0, sizeof(ck));
        if(q >= k) {
            printf("YES\n");
            for(int i=0; i<len; i++) {
                if(z == k) printf("%c", s[i]);
                else  if(ck[s[i]] == 0 && i == 0) {
                    printf("%c", s[i]);
                    ck[s[i]]++;
                    z++;
                } else if(ck[s[i]] == 0) {
                    printf("\n%c", s[i]);
                    ck[s[i]]++;
                    z++;
                } else printf("%c", s[i]);
            }
            printf("\n");
        } else printf("NO\n");
    }
    return 0;
}

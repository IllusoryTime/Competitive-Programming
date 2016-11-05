//Source Code Written: 6/3/15

#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++tc);
        char str[200+9];
        long long int d, start = 0, len, n = 0;
        scanf("%s %lld", str, &d);
        len = strlen(str);
        if(str[0]=='0') {
            printf("divisible\n");
            continue;
        }
        if(str[0]=='-') {
            len--;
            start = 1;
        }
        if(d<0) d *= -1;
        while(len--) {
            n += str[start]-'0';
            if(n >= d) {
                n %= d;
                n *= 10;
            } else n *= 10;
            start++;
        }
        if(n == 0) printf("divisible\n");
        else printf("not divisible\n");
    }
    return 0;
}

//Source Code Written: 2/23/16

#include <bits/stdc++.h>
using namespace std;
int main() {
//    freopen("in.txt", "r", stdin);
    int n, tc = 0;
    char str[12];
    scanf("%d", &n);
    for(int k=0; k<n; k++) {
        scanf("%s", str);
        int flag = 0, len = strlen(str);
        for(int i=0, j=len-1; i<len && j>=0 ; i++, j--) {
            if(str[i] != str[j]) {
                flag = 1;
                printf("Case %d: No\n", ++tc);
                break;
            }
        }
        if(!flag) printf("Case %d: Yes\n", ++tc);
    }
    return 0;
}

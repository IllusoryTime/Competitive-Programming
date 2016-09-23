//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        int len = str.size(), ans = 0;
        int arr[256];
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<len; i++) {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) arr[str[i]]++;
        }
        for(int i=0; i<len; i++) {
            if(ans < arr[str[i]]) ans = arr[str[i]];
        }
        for(int i=0; i<256; i++) {
            if(arr[i] == ans) {
                printf("%c", i);
            }
        }
        printf(" %d\n", ans);
    }
    return 0;
}

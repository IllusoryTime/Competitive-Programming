//Source Code Written: 6/3/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    string str[100+9];
    int total = 0, max_len = 0, len;
    while(getline(cin, str[total])) {
        len = str[total].size();
        if(len > max_len) max_len = len;
        total++;
    }
    for(int i=0; i<max_len; i++) {
        for(int j=total-1; j>=0; j--) {
            if(i < str[j].size()) printf("%c", str[j][i]);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        int len = str.size(), cnt = 0;;
        for(int i=0; i<len; i++) {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
                cnt++;
                while((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
                    i++;
                }
                i--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

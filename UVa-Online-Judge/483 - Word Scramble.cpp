//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    string a;
    while(getline(cin, a)) {
        int x = 0, len = a.size();
        for(int i = 0; i <= len; i++) {
            if(a[i] == ' ' || a[i] == '\0') {
                for(int j = i - 1; j >= x; j--) cout << a[j];
                if(a[i] == ' ') cout << " ";
                x = i + 1;
            }
        }
        cout << endl;
    }
    return 0;
}

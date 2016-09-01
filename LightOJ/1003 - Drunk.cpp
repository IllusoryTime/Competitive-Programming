//Source Code Written: 7/4/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    map <string, int> mymap;
    int t, tc = 0;
    scanf("%d\n", &t);
    while(t--) {
        mymap.clear();
        printf("Case %d: ", ++tc);
        int m, flag = 0;
        scanf("%d\n", &m);
        while(m--) {
            string str1, str2;
            int pos_1, pos_2;
            cin >> str1 >> str2;
            if(flag) continue;
            if(mymap.find(str1) == mymap.end()) {
                mymap[str1] = 1;
                pos_1 = 1;
            } else pos_1 = mymap[str1];
            if(mymap.find(str2) == mymap.end()) {
                mymap[str2] = 1 + pos_1;
                pos_2 = 1 + pos_1;
            } else pos_2 = mymap[str2];
            if(pos_1 > pos_2) {
                printf("No\n");
                flag = 1;
            }
        }
        if(flag == 0) {
            printf("Yes\n");
        }
        flag = 0;
    }
    return 0;
}

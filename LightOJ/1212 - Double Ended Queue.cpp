//Source Code Written: 7/2/15

#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    int n, m;
    deque <int> dq;
    scanf("%d\n", &t);
    while(t--) {
        dq.clear();
        printf("Case %d:\n", ++tc);
        scanf("%d %d\n", &n, &m);
        while(m--) {
            char str[15];
            int x;
            scanf("%s\n", str);
            if(!strcmp(str, "pushLeft")) {
                scanf("%d", &x);
                int s = dq.size();
                if(s == n) printf("The queue is full\n");
                else {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
            } else if(!strcmp(str, "pushRight")) {
                scanf("%d", &x);
                int s = dq.size();
                if(s == n) printf("The queue is full\n");
                else {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
            } else if(!strcmp(str, "popLeft")) {
                if(dq.empty()) printf("The queue is empty\n");
                else {
                    int a = dq.front();
                    dq.pop_front();
                    printf("Popped from left: %d\n", a);
                }
            } else if(!strcmp(str, "popRight")) {
                if(dq.empty()) printf("The queue is empty\n");
                else {
                    int a = dq.back();
                    dq.pop_back();
                    printf("Popped from right: %d\n", a);
                }
            }
        }
    }
    return 0;
}

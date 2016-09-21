//Source Code Written: 5/24/15

#include <bits/stdc++.h>
using namespace std;

char str[100000];
int mark[100000];

int call(int i, int j, int idx) {
    int diff = j - i, sum = 0;
    for(int x=0; x<diff; x++) {
        sum += ((str[x + i]-'0') * pow(10, diff-x-1));
    }
    mark[idx] = sum;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int n; char ch[12];
    scanf("%d", &n);
    while(n--) {
        gets(ch);
        gets(ch);
        gets(str);
        int len = strlen(str), k = 0, q = 0;
        for(int i=0; i<=len; i++) {
            if(str[i]==' ' || str[i]=='\0') {
                k++;
                call(q, i, k);
                q = i + 1;
            }
        }
        char arr[1000][1000], store[1000][1000];
        for(int i=1; i<=k; i++) {
            scanf("%s", arr[i]);
            strcpy(store[mark[i]] , arr[i]);
        }
        for(int i=1; i<=k; i++) {
            cout << store[i] << endl;
        }
        if(n != 0) cout << endl;
    }
    return 0;
}

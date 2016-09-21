//Source Code Written: 9/21/16

#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
char str[N], ch[N], store[1000][1000];
int pos[1000];

int power(int b, int p) {
    int ans = 1;
    while(p--) ans *= b;
    return ans;
}

int first_call(int i, int j, int idx) {
    int diff = j - i, sum = 0;
    for(int x = 0; x < diff; x++) {
        sum += ((ch[x+i]-'0') * power(10, diff-x-1));
    }
    pos[idx] = sum;
}

int second_call(int i, int j, int idx) {
    int diff = j - i, cnt = 0;
    char temp[N];
    for(int x = 0; x < diff; x++) {
        temp[cnt++] = str[x+i];
    }
    temp[cnt] = '\0';
    strcpy(store[pos[idx]], temp);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, len, k, q;
    scanf("%d\n", &n);
    while(n--) {
        gets(ch);
        gets(str);
        getchar();
        len = strlen(ch), k = 0, q = 0;
        for(int i=0; i<=len; i++) {
            if(ch[i] == ' ' || ch[i] == '\0') {
                k++;
                first_call(q, i, k);
                q = i+1;
            }
        }
        len = strlen(str), k = 0, q = 0;
        for(int i=0; i<=len; i++) {
            if(str[i] == ' ' || str[i] == '\0') {
                k++;
                second_call(q, i, k);
                q = i+1;
            }
        }
        for(int i=1; i<=k; i++) cout << store[i] << endl;
        if(n != 0) cout << endl;
    }
    return 0;
}

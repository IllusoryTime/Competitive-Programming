//Problem Solved: 5/26/15
//Last Edit: 9/29/16

#include<bits/stdc++.h>
using namespace std;

char str[1000+2];
bool palindrome(int i, int j) {
    for(int k=i; k<j; k++) {
        if(str[k] != str[j]) {
            return false;
        }
        j--;
    }
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int k, len, t, cnt = 0;
    cin >> str >> k;
    len = strlen(str);
    t = len/k;
    if(len%k) {
        printf("NO\n");
        return 0;
    }
    for(int i=0; i<len; i+=t) {
        if(palindrome(i, i+t-1)) cnt++;
    }
    if(cnt == k) printf("YES\n");
    else printf("NO\n");
    return 0;
}


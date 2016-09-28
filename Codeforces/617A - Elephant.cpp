//Problem Solved: 1/23/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
    ///freopen("in.txt", "r", stdin);
    int n, k, p;
    while(cin >> n) {
        int ans = n / 5;
        if(n % 5) ans++;
        cout<< ans <<endl;
    }
    return 0;
}

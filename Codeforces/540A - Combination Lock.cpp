//Problem Solved: 5/19/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int n, sum = 0;;
    char a[1000+9], b[1000+9];
    cin >> n;
    cin >> a >> b;
    for(int i=0 ; i<n; i++) {
        if(abs(b[i]-a[i]) < (10 - abs(b[i]-a[i]))) sum += abs(b[i]-a[i]);
        else sum += (10 - abs(b[i]-a[i]));
    }
    printf("%d\n", sum);
    return 0;
}

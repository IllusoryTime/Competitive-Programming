//Problem Solved: 8/22/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    int na, nb, m, k, a1[100000+9], a2[100000+9];
    cin >> na >> nb;
    cin >> k >> m;
    for(int i=1; i<=na; i++) cin >> a1[i];
    for(int i=1; i<=nb; i++) cin >> a2[i];
    int t = upper_bound(a2+1, a2+nb+1, a1[k]) - a2;
    if(nb - t + 1 >= m) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}


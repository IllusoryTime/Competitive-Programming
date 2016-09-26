//Problem Solved: 12/2/14
//Last Edit: 9/27/16

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define mod 100000000

long long int dp[101][101][11][11];
int n1, n2, k1, k2;

long long int call(int i, int j, int p, int q) {
    if (i < 0 || j < 0 || p < 0 || q < 0)
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(dp[i][j][p][q] != -1)
        return dp[i][j][p][q];
    return dp[i][j][p][q] = (call(i-1, j, p-1, k2) + call(i, j-1, k1, q-1)) % mod;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << call(n1, n2, k1, k2) << endl;
    return 0;
}

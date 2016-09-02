//Source Code Written: 6/3/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        int arr[26], n, k;
        for(int i=0; i<26; i++) arr[i] = i + 'A';
        printf("Case %d:\n", ++tc);
        cin >> n >> k;
        k--;
        do {
            for(int i=0; i<n; i++) printf("%c", arr[i]);
            printf("\n", k);
        } while(next_permutation(arr, arr + n) && k--);
    }
    return 0;
}

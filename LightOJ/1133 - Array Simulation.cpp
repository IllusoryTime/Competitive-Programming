//Source Code Written: 3/21/15

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
const int N = 102;

int main() {
    int t, tc = 0;
    cin >> t;
    while(t--) {
        printf("Case %d:\n", ++tc);
        int n, m, arr[N], arr1[N], x, y, k;
        char ch;
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> arr[i-1];
        while(m--) {
            cin >> ch;
            if(ch == 'P') {
                cin >> x >> y;
                swap(arr[x], arr[y]);
            } else if(ch == 'S') {
                cin >> x;
                for(int i=0; i<n; i++)
                    arr[i] += x;
            } else if(ch == 'M') {
                cin >> x;
                for(int i=0; i<n; i++)
                    arr[i] *= x;
            } else if(ch == 'D') {
                cin >> x;
                for(int i=0; i<n; i++)
                    arr[i] /= x;
            } else if(ch == 'R') {
                for(int i=0; i<n/2; i++) {
                    swap(arr[i] , arr[n-i-1]);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

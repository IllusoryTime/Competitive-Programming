//Source Code Written: 3/21/15

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int test, caseno = 0;
    cin >> test;
    while(test--) {
        int x, y;
        printf("Case %d: ", ++caseno);
        cin >> x >> y;
        if(y-x < 0) printf("%d\n", (((x-y)+x)*4)+19);
        else printf("%d\n", (y*4)+19);
    }
    return 0;
}

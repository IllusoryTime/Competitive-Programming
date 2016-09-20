//Source Code Written: 3/11/15

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, caseno = 0, cases;
    int x, y, x1, x2, y1, y2, m;
    scanf("%d", &cases);
    while(cases--) {
        printf("Case %d:\n", ++caseno);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &m);
        while(m--) {
            scanf("%d %d", &x, &y);
            if((x >= x1  && x <= x2) && (y >= y1 && y <= y2)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

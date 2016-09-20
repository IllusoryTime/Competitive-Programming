//Source Code Written: 6/1/15

#include <bits/stdc++.h>
using namespace std;

struct xy {
    double x1,x2,y1,y2;
} coordinate[12];

int main() {
    //freopen("in.txt", "r",stdin);
    char ch[3], k = 1;;
    while(scanf("%s", ch) == 1) {
        if(ch[0] == '*') break;
        else if(ch[0] == 'r') {
            cin >> coordinate[k].x1 >> coordinate[k].y1 >> coordinate[k].x2 >> coordinate[k].y2;
            k++;
        }
    }
    double x, y;
    int no = 1;
    while(scanf("%lf %lf", &x, &y) == 2) {
        if(x == 9999.9 && y == 9999.9) break;
        else {
            int temp = 0;
            for(int i = 1; i < k; i++) {
                if(x > coordinate[i].x1 && x < coordinate[i].x2 && y < coordinate[i].y1 && y > coordinate[i].y2) {
                    printf("Point %d is contained in figure %d\n", no, i);
                    temp++;
                }
            }
            if(temp == 0) printf("Point %d is not contained in any figure\n", no);
        }
        no++;
    }
    return 0;
}

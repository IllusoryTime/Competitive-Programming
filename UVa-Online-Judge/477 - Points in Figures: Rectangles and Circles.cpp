//Source Code Written: 6/1/15

#include <bits/stdc++.h>
using namespace std;

struct xy {
    double x1, x2, y1, y2;
} coordinate[12];

struct xyr {
    double x1, y1, r1;
} circle[12];

double distancess(double x, double y, int i) {
    double q, w;
    q = (x - circle[i].x1) * (x - circle[i].x1);
    w = (y - circle[i].y1) * (y - circle[i].y1);
    q += w;
    q = sqrt(q);
    return q;
}

int main() {
    //freopen("in.txt", "r",stdin);
    char ch[3];
    int k = 1, c = 1, x1 = 1, rec[12], cir[12];
    while(scanf("%s", ch)==1) {
        if(ch[0] == '*') break;
        else if(ch[0] == 'r') {
            cin >> coordinate[k].x1 >> coordinate[k].y1 >> coordinate[k].x2 >> coordinate[k].y2;
            rec[k]= x1;
            k++;
            x1++;
        } else if(ch[0]=='c') {
            cin >> circle[c].x1 >> circle[c].y1 >> circle[c].r1;
            cir[c] = x1;
            c++;
            x1++;
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
                    printf("Point %d is contained in figure %d\n", no, rec[i]);
                    temp++;
                }
            }
            for(int i = 1; i < c; i++) {
                if(distancess(x, y, i) < circle[i].r1) {
                    printf("Point %d is contained in figure %d\n", no, cir[i]);
                    temp++;
                }
            }
            if(temp == 0) printf("Point %d is not contained in any figure\n", no);
        }
        no++;
    }
    return 0;
}

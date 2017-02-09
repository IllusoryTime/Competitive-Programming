//Source Code Written: 6/10/15

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000+7
#define PI acos(-1.0)
#define sq(x) ((x)*(x))
const double esp = 1e-9;
double d;
int n, nc;
struct pt {
    double x, y;
} p[MAX], c[MAX];

double area(const pt &o, const pt &a, const pt &b) {
    return ((a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y));
}
double dist(const pt &a, const pt &b) {
    return sqrt(sq(a.x-b.x) + sq(a.y-b.y));
}
bool angcmp(const pt &a, const pt &b) {
    double temp = area(p[0], a, b);
    if(!temp) return (dist(p[0], a) + esp < dist(p[0], b));
    else return temp > -esp;
}
double chap(const pt &a, const pt &b, const pt &c) {
    double A = sqrt(sq(b.x - c.x) + sq(b.y - c.y));
    double B = sqrt(sq(a.x - c.x) + sq(a.y - c.y));
    double C = sqrt(sq(a.x - b.x) + sq(a.y - b.y));
    double ang = acos((A * A + C * C - B * B) / (2 * A * C));
    ang = PI-ang;
    return d*ang;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %lf", &n, &d);
        int MIN = 0, nc;
        double sum = 0;
        for(int i=0; i<n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if((p[i].y<p[MIN].y) || (p[i].y==p[MIN].y && p[i].x<p[MIN].x)) {
                MIN = i;
            }
        }
        printf("Case %d: ", ++tc);
        if(n == 1) {
            printf("%.7lf\n", 2*PI*d);
            continue;
        } else if(n == 2) {
            sum += (2*dist(p[0], p[1]));
            sum += (2*PI*d);
            printf("%.7lf\n", sum);
            continue;
        }
        swap(p[0], p[MIN]);
        sort(p+1, p+n, angcmp);
        p[n] = p[0];
        nc = 2;
        for(int i=0; i<2; i++) c[i] = p[i];
        for(int i=2; i<=n; i++) {
            while(nc>=2 && area(c[nc-2], c[nc-1], p[i])<0) nc--;
            c[nc++] = p[i];
        }
        c[nc] = c[1];
        for(int i=0; i<=nc-2; i++) sum += dist(c[i], c[i+1]);
        sum += PI*2*d;
        printf("%.7lf\n", sum);
    }
    return 0;
}

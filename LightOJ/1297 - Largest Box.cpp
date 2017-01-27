//Source Code Written: 1/27/17

#include <bits/stdc++.h>
using namespace std;

double l, w;
double area(double x) {
    return (l - 2 * x) * (w - 2 * x) * x;
}

int main() {
    double t, tc = 0, x1, x2, ans, total;
    cin >> t;
    while(t--) {
        cin >> l >> w;
        total = l + w;
        x1 = (4.0 * total + sqrt(16 * total * total - 48 * l * w)) / 24.0;
        x2 = (4.0 * total - sqrt(16 * total * total - 48 * l * w)) / 24.0;
        ans = INT_MIN;
        ans = max(max(ans, area(x1)), area(x2));
        printf("Case %.0lf: %.9lf\n", ++tc, ans);
    }
    return 0;
}

//Source Code Written: 5/22/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, test, day1, year1, day2, year2, k;
    char month1[15], month2[15], ch[4];
    cin >> test;
    for(i=1; i<=test; i++) {
        int LP1 = 1, LP2 = 1, LP = 1;
        cin >> month1 >> day1 >> ch >> year1;
        cin >> month2 >> day2 >> ch >> year2;
        LP1 += year2/4;
        LP1 -= year2/100;
        LP1 += year2/400;
        LP2 += year1/4;
        LP2 -= year1/100;
        LP2 += year1/400;
        LP = LP1 - LP2;
        if(year1%400 == 0 || (year1%100 != 0 && year1%4 == 0)) {
            int f = strcmp(month1, "January");
            int g = strcmp(month1, "February");
            if(f==0 || g==0) LP++;
        }
        if(year2%400 == 0 || (year2%100 != 0 && year2%4 == 0)) {
            int f = strcmp(month2, "January");
            int g = strcmp(month2, "February");
            if((f==0 || g==0)) {
                if(day2 != 29) LP--;
            }
        }
        printf("Case %d: %d\n", i, LP);
    }
    return 0;
}

//Source Code Written: 5/22/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, test, day1, year1, day2, year2, k;
    char month1[15], month2[15], ch[4];
    cin >> test;
    for(i=1; i<=test; i++) {
        int ly1 = 1, ly2 = 1, ly = 1;
        cin >> month1 >> day1 >> ch >> year1;
        cin >> month2 >> day2 >> ch >> year2;
        int year3 = year2-2000;;
        ly1 += year2/4;
        ly1 -= year2/100;
        ly1 += year2/400;
        int year4 = year1-2000;;
        ly2 += year1/4;
        ly2 -= year1/100;
        ly2 += year1/400;
        ly = ly1 - ly2;
        if(year1%400 == 0 || (year1%100 != 0 && year1%4 == 0)) {
            int f = strcmp(month1, "January");
            int g = strcmp(month1, "February");
            if(f==0 || g==0) ly++;
        }
        if(year2%400 == 0 || (year2%100 != 0 && year2%4 == 0)) {
            int f = strcmp(month2, "January");
            int g = strcmp(month2, "February");
            if((f==0 || g==0)) {
                if(day2 != 29) ly--;
            }
        }
        printf("Case %d: %d\n", i, ly);
    }
    return 0;
}

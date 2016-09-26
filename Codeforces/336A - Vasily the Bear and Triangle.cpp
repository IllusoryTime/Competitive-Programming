//Problem Solved: 8/9/13
//Last Update: 9/27/16

#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x>0 && y>0) printf("0 %d %d 0\n", x+y, x+y);
    else if(x>0 && y<0) printf("0 -%d %d 0\n", x+y-2*y, x+y-2*y);
    else if(x<0 && y>0) printf("-%d 0 0 %d\n", x+y-2*x, x+y-2*x);
    else if(x<0 && y<0) printf("-%d 0 0 -%d\n", x+y-2*x-2*y, x+y-2*x-2*y);
    return 0;
}

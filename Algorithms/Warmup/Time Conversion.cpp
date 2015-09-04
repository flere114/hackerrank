#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int h,m,s;
    char c1,c2;
    scanf("%2d:%2d:%2d%c%c",&h,&m,&s,&c1,&c2);
    if(h==12 && c1=='A') printf("00:%02d:%02d\n",m,s);
    else if(h==12 && c1=='P') printf("12:%02d:%02d\n",m,s);
    else if(c1=='A'){
        printf("%02d:%02d:%02d",h,m,s);
    }else{
        printf("%02d:%02d:%02d",h+12,m,s);
    }
    return 0;
}

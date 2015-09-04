#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m1,m2,d1,d2,y1,y2;
    scanf(" %d %d %d %d %d %d",&d1,&m1,&y1,&d2,&m2,&y2);
    if(y1<y2){
        printf("0\n");
    }else if(y1>y2){
        printf("10000\n");
    }else{
        if(m1<m2){
            printf("0\n");
        }else if(m1>m2){
            printf("%d\n",500*(m1-m2));
        }else{
            if(d1<=d2)  printf("0\n");
            else    printf("%d\n",15*(d1-d2));
        }
    }
    
    return 0;
}

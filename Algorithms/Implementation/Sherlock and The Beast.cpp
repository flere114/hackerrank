#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int u = -1, v = -1;
        for(u=0;5*u<=N;u++){
            if((N-5*u)%3==0){
                v = (N-5*u)/3;
                break;
            }
        }
        if(v==-1){
            printf("-1\n");
            continue;
        }
        for(int i=0;i<3*v;i++)  printf("5");
        for(int i=0;i<5*u;i++)  printf("3");
        printf("\n");
    }
    return 0;
}

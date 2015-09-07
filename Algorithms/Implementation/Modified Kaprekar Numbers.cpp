#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool is[100005];
int ten[7] = {1,10,100,1000,10000,100000,1000000};

void pre(){
    memset(is,false,sizeof(is));
    for(long long i=1;i<100000;i++){
        int d = 0;
        long long tmp = i;
        while(tmp>0)
            d++, tmp /= 10;
        tmp = i*i;
        int R = tmp%ten[d], L = tmp/ten[d];
        if(R+L == i)    is[i] = true;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    pre();
    int a,b,re = 0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        if(is[i]){
            if(re==1)   printf(" ");
            printf("%d",i);
            re = 1;
        }
    }
    if(re==1)   printf("\n");
    else    printf("INVALID RANGE\n");
    
    return 0;
}

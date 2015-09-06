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
    for(int t=0,N,K;t<T && scanf(" %d %d",&N,&K)==2;t++){
        for(int i=0,x;i<N && scanf(" %d",&x)==1;i++)
            if(x<=0)    K--;
        if(K>0) printf("YES\n");
        else    printf("NO\n");
    }
    
    return 0;
}

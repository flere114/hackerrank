#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000006];

int rec(int L,int R,int th){
    if(R-L==1)  return a[L];
    int c = L;
    int pp = rand()%(R-L) + L;
    swap(a[pp],a[R-1]);
    for(int i=L;i<R-1;i++){
        if(a[i]<a[R-1])
            swap(a[i],a[c]), c++;
    }
    swap(a[R-1],a[c]);
    if(c-L==th)   return a[c];
    else if(th<c-L)   return rec(L,c,th);
    else    return rec(c+1,R,th-(c-L+1));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    scanf(" %d",&N);
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    
    printf("%d",rec(0,N,N/2));
    
    return 0;
}

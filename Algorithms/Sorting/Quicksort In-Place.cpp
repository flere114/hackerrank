#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

void quickSort(int L,int R,int *a){
    if(R-L <= 1)    return;
    int p = a[R-1],c = L;
    for(int i=L;i<R-1;i++){
        if(a[i]<p){
            swap(a[i],a[c]);
            c++;
        }
    }
    swap(a[R-1],a[c]);
    for(int i=0;i<N;i++)
        if(i==0)    printf("%d",a[i]);
        else    printf(" %d",a[i]);
    printf("\n");
    quickSort(L,c,a);
    quickSort(c+1,R,a);
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[5005];
    scanf(" %d",&N);
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    
    quickSort(0,N,a);
    
    return 0;
}

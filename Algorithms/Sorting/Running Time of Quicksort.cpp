#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N,ans1,ans2;

void quickSort(int L,int R,int *a){
    if(R-L <= 1)    return;
    int p = a[R-1],c = L;
    for(int i=L;i<R-1;i++){
        if(a[i]<p){
            swap(a[i],a[c]);
            ans2++;
            c++;
        }
    }
    swap(a[R-1],a[c]);
    ans2++;
    quickSort(L,c,a);
    quickSort(c+1,R,a);
    
}
void insertionSort(int ar_size, int *  ar) {
    for(int i=1;i<ar_size;i++){
        for(int j=i-1;j>=0;j--){
            if(ar[j+1]<ar[j]){
                swap(ar[j+1],ar[j]);
                ans1++;
            }
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[1005],b[1005];
    scanf(" %d",&N);
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++)
        b[i] = a[i];
    
    ans1 = ans2 = 0;
    quickSort(0,N,a);
    insertionSort(N,b);
    printf("%d\n",ans1-ans2);
    
    return 0;
}

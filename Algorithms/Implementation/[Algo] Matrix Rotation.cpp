#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[305][305];
vector <int> v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,BR;
    scanf(" %d %d %d",&N,&M,&BR);
    for(int i=0;i<N;i++)
        for(int j=0;j<M && scanf(" %d",&a[i][j])==1;j++);
    int L = 0, R = M-1, U = 0, D = N-1, tmpN = N, tmpM = M;
    while(L<R && U<D){
        v.clear();
        for(int i=U;i<=D;i++)   v.push_back(a[i][L]);
        for(int i=L+1;i<=R;i++) v.push_back(a[D][i]);
        for(int i=D-1;i>=U;i--) v.push_back(a[i][R]);
        for(int i=R-1;i>L;i--)  v.push_back(a[U][i]);
        
        int sz = v.size();
        int RR = BR % sz;
        int r = 0;
        
        for(int i=U;i<=D;i++)   a[i][L] = v[(r-RR+sz)%sz], r++;
        for(int i=L+1;i<=R;i++) a[D][i] = v[(r-RR+sz)%sz], r++;
        for(int i=D-1;i>=U;i--) a[i][R] = v[(r-RR+sz)%sz], r++;
        for(int i=R-1;i>L;i--)  a[U][i] = v[(r-RR+sz)%sz], r++;
        
        tmpN -= 2, tmpM -= 2;
        L++, R--, U++, D--;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(j==0)    printf("%d",a[i][j]);
            else    printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

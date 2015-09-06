/*
 Key idea : minimum spanning tree
 
 We need to calculate a maximum spanning tree, when building, we need to check two things:
 1. these two points have been in the same subset
 2. both subsets of these two points have a dangerous city
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct A{
    int x,y,z;
    A(){}
    A(int _x,int _y,int _z){
        x = _x, y = _y, z = _z;
    }
}AA;
vector <AA> v;
int N,M,se[100005],is[100005];

bool cmp(AA c,AA d){
    return c.z > d.z;
}
int fin(int i){
    if(i==se[i])    return i;
    int t = fin(se[i]);
    se[i] = t;
    if(is[se[i]]==1)    is[t] = 1;
    return t;
}
long long kruskal(){
    long long ret = 0;
    for(int i=0;i<N-1;i++){
        int rx = fin(v[i].x);
        int ry = fin(v[i].y);
        if(rx==ry)  continue;
        if(is[rx]==1 && is[ry]==1)  continue;
        se[rx] = ry;
        if(is[rx]==1)   is[ry] = 1;
        ret += v[i].z;
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long all = 0;
    scanf(" %d %d",&N,&M);
    v.clear();
    for(int i=0,x,y,z;i<N-1 && scanf(" %d %d %d",&x,&y,&z)==3;i++)
        v.push_back(AA(x,y,z)), all += z;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<N;i++)
        se[i] = i, is[i] = 0;
    for(int i=0,x;i<M && scanf(" %d",&x)==1;i++)
        is[x] = 1;
    printf("%lld\n",all-kruskal());
    
    return 0;
}

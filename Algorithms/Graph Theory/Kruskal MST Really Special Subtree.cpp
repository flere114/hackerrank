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
int se[3003];

bool cmp(AA c,AA d){
    return c.z < d.z;
}
int fin(int i){
    return i==se[i] ? i : se[i] = fin(se[i]);
}
int kruskal(int N){
    for(int i=0;i<=N;i++)
        se[i] = i;
    int ret = 0;
    for(int i=0,c=0;i<v.size() && c<N-1;i++){
        int rx = fin(v[i].x);
        int ry = fin(v[i].y);
        if(rx!=ry){
            se[rx] = ry;
            ret += v[i].z;
            c++;
        }
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    
    v.clear();
    for(int i=0,x,y,z;i<M && scanf(" %d %d %d",&x,&y,&z)==3;i++)
        v.push_back(AA(x,y,z));
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",kruskal(N));
    
    return 0;
}

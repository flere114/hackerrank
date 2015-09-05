/*
 try this test case : 5 5 4 3 2 1
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct A{
    int v,pos;
    A(){}
    A(int _v,int _pos){
        v = _v, pos = _pos;
    }
}AA;
vector <AA> v;

bool cmp(AA c,AA d){
    if(c.v!=d.v)    return c.v < d.v;
    return c.pos < d.pos;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    v.clear();
    for(int i=0,x;i<N && scanf(" %d",&x)==1;i++)
        v.push_back(AA(x,i));
    sort(v.begin(),v.end(),cmp);
    
    vector <int> d;
    for(int i=0;i<N;i++)
        if(v[i].pos != i)
            d.push_back(i);
    if(d.size()==0){
        printf("yes\n");
    }else if(d.size()==2){
        printf("yes\nswap %d %d\n",d[0]+1,d[1]+1);
    }else{
        int conti = 1;
        /*for(int i=1;i<d.size();i++)
         if(v[d[i-1]].pos-1 != v[d[i]].pos)
         conti = 0;
         */
        for(int i=d[0];i<d[d.size()-1]-1;i++)
            if(v[i].pos-1 != v[i+1].pos)
                conti = 0;
        if(conti==0){
            printf("no\n");
        }else{
            printf("yes\nreverse %d %d\n",d[0]+1,d[d.size()-1]+1);
        }
    }
    
    return 0;
}

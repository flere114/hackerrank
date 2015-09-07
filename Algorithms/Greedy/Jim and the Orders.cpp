#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct A{
    int id,ed;
    A(){};
    A(int _id,int _ed){
        id = _id, ed = _ed;
    }
}AA;
vector <AA> v;

bool cmp(AA c,AA d){
    if(c.ed!=d.ed)  return c.ed < d.ed;
    else    return c.id < d.id;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    for(int i=0,t,d;i<N && scanf(" %d %d",&t,&d)==2;i++)
        v.push_back(AA(i+1,t+d));
    sort(v.begin(),v.end(),cmp);
    printf("%d",v[0].id);
    for(int i=1;i<v.size();i++)
        printf(" %d",v[i].id);
    printf("\n");
    
    return 0;
}

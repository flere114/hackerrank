/*
 You have to be very careful to several points, it's better that you can think all of them yourself.
 
 1. We need to reverse all the edges.
 
 2. Detect cycle.
 2-a. Check if N can reach any one of the cycle.
 2-b. If N can reach a cycle, we need also check if the point in this cycle can reach 1 or not.
      Think this example:
      5 5
      1 5
      4 5
      3 4
      2 3
      4 2
      The answer of this example is 1, though N can reach a cycle 2-3-4
 2-c. So if N can reach a cycle, and from the cycle we also can reach 1, then the asnwer is infinite
 2-d. If time limit exceed, you can need to take care two things:
 2-d-1. For each cycle, we only use one point to check whether it can reach 1 or not.
 2-d-2. When checking, use some technique to avoid repetitive initialization. (My in[] array)
 
 3. Recursive calculate the answer from N. (Dynamic programming technique)
 3-a. If you know how to detect the cycle, appying it in this function. Or you will get into the cycle and get a segmentation fault.
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

vector <int> v[10004];
int is[10004],in[10004],ans[10004];
const int MOD = 1000000000;

bool can_reach_st(int x){
    queue <int> q;
    q.push(x);
    in[x] = x;
    while(!q.empty()){
        int now = q.front();    q.pop();
        for(int i=0;i<v[now].size();i++){
            int y = v[now][i];
            if(in[y]!=x)
                in[y] = x, q.push(y);
        }
    }
    return in[1]==x;
}
bool has_cycle(int x){
    is[x] = 1;
    bool ret = false;
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(is[y]==0)    ret = ret | has_cycle(y);
        else if(is[y]==1){
            ret = ret | can_reach_st(x);
        }
        if(ret) return ret;
    }
    is[x] = 2;
    return ret;
}
int rec(int x){
    if(ans[x]!=-1)   return ans[x];
    is[x] = 1;
    int c = 0;
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i];
        if(is[y]==1)    continue;
        c += rec(y);
        c %= MOD;
    }
    is[x] = 2;
    return ans[x] = c;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    
    for(int i=0;i<=N;i++)
        v[i].clear(), is[i] = in[i] = 0, ans[i] = -1;
    for(int i=0,x,y;i<M && scanf(" %d %d",&x,&y)==2;i++)
        v[y].push_back(x);
    if(has_cycle(N)){
        printf("INFINITE PATHS\n");
        return 0;
    }
    ans[1] = 1;
    memset(is,0,sizeof(is));
    printf("%d\n",rec(N));
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

char ss[2][12];
int s[2][12],N;
bool is[1<<21];

int to(){
    int ret = 0;
    for(int i=0;i<2;i++)
        for(int j=0;j<N;j++)
            if(s[i][j]==1)
                ret |= (1<<(i*N+j));
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T &&  scanf(" %d",&N)==1;t++){
        scanf(" %s %s",ss[0],ss[1]);
        for(int i=0;i<2;i++)
            for(int j=0;j<N;j++)
                s[i][j] = ss[i][j]-'0';
        int tmp = 1<<(2*N);
        for(int i=0;i<tmp;i++)
            is[i] = false;
        queue <int> q;
        q.push(to());
        is[to()] = true;
        
        while(!q.empty()){
            int x = q.front();  q.pop();
            if(x==tmp-1)    break;
            for(int i=0;i<N;i++){
                if((x & (1<<i))==0){
                    if(i+1<N && (x & (1<<(i+1)))==0){
                        int nx = x | (1<<i) | (1<<(i+1));
                        if(!is[nx]){
                            is[nx] = true;
                            q.push(nx);
                        }
                    }
                    if((x & (1<<(N+i))) == 0){
                        int nx = x | (1<<i) | (1<<(N+i));
                        if(!is[nx]){
                            is[nx] = true;
                            q.push(nx);
                        }
                    }
                    if(i-1>=0 && (x & (1<<(N+i-1)))==0){
                        int nx = x | (1<<i) | (1<<(N+i-1));
                        if(!is[nx]){
                            is[nx] = true;
                            q.push(nx);
                        }
                    }
                }
            }
            for(int i=0;i<N;i++){
                if((x & (1<<(N+i)))==0){
                    if(i+1<N && (x & (1<<(N+i+1)))==0){
                        int nx = x | (1<<(N+i)) | (1<<(N+i+1));
                        if(!is[nx]){
                            is[nx] = true;
                            q.push(nx);
                        }
                    }
                }
            }
        }
        
        if(is[tmp-1])   printf("YES\n");
        else    printf("NO\n");
    }
    
    return 0;
}

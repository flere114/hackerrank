#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[1600],s2[1600];
int len1, len2, S;

int cal(int x,int y){
    int err = 0, ret = 0, i = x, j = y, l1 = x, l2 = y;
    for(;i<len1 && j<len2;i++,j++){
        if(s1[i]==s2[j]){
            ret = max(ret,i-l1+1);
            continue;
        }
        err++;
        if(err>S){
            for(;;l1++,l2++)
                if(s1[l1]!=s2[l2]){
                    err--;
                    l1++, l2++;
                    break;
                }
        }
        if(i>=l1)
            ret = max(ret,i-l1+1);
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %d %s %s",&S,s1,s2);
        int ans = 0;
        len1 = strlen(s1), len2 = strlen(s2);
        for(int i=0;i<len2;i++)
            ans = max(ans,cal(0,i));
        for(int i=0;i<len1;i++)
            ans = max(ans,cal(i,0));
        printf("%d\n",ans);
    }
    
    return 0;
}

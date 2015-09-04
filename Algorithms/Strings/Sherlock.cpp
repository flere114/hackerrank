#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[102];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int len = strlen(s),c[102][26],ans = 0;
        memset(c,0,sizeof(c));
        for(int i=0;i<len;i++)  if(s[i]>='A' && s[i]<='Z')  while(1);
        for(int i=0;i<len;i++)  c[i+1][s[i]-'a']++;
        for(int i=0;i<26;i++)
            for(int j=2;j<=len;j++)
                c[j][i] += c[j-1][i];
        for(int k=1;k<len;k++){
            for(int st1=1;st1+k-1<=len;st1++){
                for(int st2=st1+1,re=1;st2+k-1<=len;st2++,re=1){
                    for(int i=0;i<26;i++)
                        if(c[st1+k-1][i]-c[st1-1][i]-c[st2+k-1][i]+c[st2-1][i]!=0)
                            re = 0;
                    ans += re;
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}

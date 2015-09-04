#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[10004],ans[10004];
int nd[26][10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf(" %s",s);
    int len = strlen(s),c[26],t[26];
    for(int i=0;i<len/2;i++)
        swap(s[i],s[len-i-1]);
    memset(c,0,sizeof(c));
    memset(t,0,sizeof(t));
    memset(nd,0,sizeof(nd));
    
    for(int i=0;i<len;i++)  c[s[i]-'a']++;
    for(int i=0;i<26;i++)   c[i]>>=1;
    for(int i=0;i<len;i++){
        t[s[i]-'a']++;
        int left = c[s[i]-'a']*2 - t[s[i]-'a'];
        if(c[s[i]-'a'] > left)  nd[s[i]-'a'][i] = c[s[i]-'a']-left;
    }
    //for(int i=0;i<len;i++)
    //  printf("%d ",nd[0][i]);
    memset(t,0,sizeof(t));
    int last = 0, pos = 0;
    for(int i=0;i<len;i++){
        if(t[s[i]-'a'] >= nd[s[i]-'a'][i]) continue;
        for(int j=0;j<s[i]-'a';j++){
            if(c[j]==0) continue;
            for(int k=last;k<=i && c[j]>0;k++){
                if(s[k]-'a' == j){
                    ans[pos++] = s[k];
                    t[j]++;
                    c[j]--;
                    last = k+1;
                }
            }
        }
        for(int k=last;k<=i && c[s[i]-'a']>0 && t[s[i]-'a'] < nd[s[i]-'a'][i];k++){
            if(s[k]==s[i]){
                ans[pos++] = s[k];
                t[s[i]-'a']++;
                c[s[i]-'a']--;
                last = k+1;
            }
        }
    }
    //printf("pos = %d\n",pos);
    for(int i=0;i<pos;i++)
        printf("%c",ans[i]);
    printf("\n");
    
    return 0;
}

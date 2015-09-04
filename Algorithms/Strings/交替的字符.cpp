#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int len = strlen(s);
        int ans = 0;
        for(int i=0;i<len-1;i++)
            if(s[i]==s[i+1])
                ans++;
        printf("%d\n",ans);
    }
    
    return 0;
}

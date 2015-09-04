#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int len = strlen(s);
        int ans = 0;
        for(int i=0;i<len/2;i++)
            ans += abs(s[i]-s[len-i-1]);
        printf("%d\n",ans);
    }
    
    return 0;
}

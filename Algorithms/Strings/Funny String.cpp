#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[10004],ss[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int re = 0, len = strlen(s);
        for(int i=0;i<len;i++)  ss[i] = s[len-i-1];
        for(int i=0;i+1<=len/2 && re==0;i++)
            if(abs(s[i+1]-s[i])!=abs(ss[i+1]-ss[i]))
                re = 1;
        if(re==0)   printf("Funny\n");
        else    printf("Not Funny\n");
    }
    
    return 0;
}

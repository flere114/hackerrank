#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int c[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    memset(c,0,sizeof(c));
    for(int i=0,x;i<N && cin >> x;i++)
        c[x]++;
    int ans = 0;
    for(int i=0;i<=10000;){
        if(c[i]>0)  ans++, i += 5;
        else    i++;
    }
    printf("%d\n",ans);
    
    return 0;
}

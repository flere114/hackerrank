#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    long long N;
    cin >> T;
    for(int t=0;t<T && cin >> N;t++){
        int ans = 0;
        long long tmp = N;
        for(;tmp>0;tmp /= 10){
            int c = tmp%10;
            if(c>0 && N%c==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

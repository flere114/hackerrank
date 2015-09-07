#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    long long B,W,X,Y,Z;
    cin >> T;
    for(int t=0;t<T && cin >> B >> W >> X >> Y >> Z;t++){
        if(X+Z < Y){
            printf("%lld\n",X * (B+W) + Z*W);
        }else if(Y+Z < X){
            printf("%lld\n",Y * (B+W) + Z*B);
        }else{
            printf("%lld\n",X*B + Y*W);
        }
    }
    return 0;
}

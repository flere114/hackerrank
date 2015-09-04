#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,ans1 = 0, ans2 = 0;
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0,x;j<N && cin>>x;j++){
            if(i==j)    ans1 += x;
            if(i+j==N-1)   ans2 += x;
        }
    cout << abs(ans1-ans2) << endl;
    return 0;
}

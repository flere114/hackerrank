#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,ans1 = 0,ans2 = 0,ans3 = 0;
    cin >> N;
    for(int i=0,x;i<N && cin>>x;i++)
        if(x>0) ans1++;
        else if(x==0)   ans2++;
        else    ans3++;
    printf("%.3lf\n%.3lf\n%.3lf\n",(double)ans1/N,(double)ans3/N,(double)ans2/N);
    return 0;
}

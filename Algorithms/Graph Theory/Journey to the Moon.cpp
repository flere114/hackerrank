#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

int se[100005],c[100005];

int fin(int i){
    return se[i]==i ? i : se[i]=fin(se[i]);
}

int main()
{
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for(int i=0;i<N;i++)
        se[i] = i, c[i] = 0;
    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
        int ra = fin(a);
        int rb = fin(b);
        if(ra!=rb)
            se[ra] = rb;
    }
    
    long long result = 0;
    
    /** Write code to compute the result using N,I,pairs **/
    for(int i=0;i<N;i++)
        c[fin(i)]++;
    int left = N;
    for(int i=0;i<N;i++){
        if(c[i]>0){
            left -= c[i];
            result += (long long)left * c[i];
        }
    }
    
    cout << result << endl;
    return 0;
}

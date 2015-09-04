#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {
    if(ar.size()==1){
        printf("%d\n",ar[0]);
        return;
    }
    int v = ar[ar.size()-1];
    ar[ar.size()-1] = ar[ar.size()-2];
    for(int i=ar.size()-1;i>0;i--){
        
        if(v>ar[i]){
            ar[i] = v;
            break;
        }else{
            printf("%d",ar[0]);
            for(int j=1;j<ar.size();j++)
                printf(" %d",ar[j]);
            printf("\n");
            if(i>1)  ar[i-1] = ar[i-2];
            else    ar[i-1] = v;
        }
    }
    printf("%d",ar[0]);
    for(int j=1;j<ar.size();j++)
        printf(" %d",ar[j]);
    printf("\n");
    
}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }
    
    insertionSort(_ar);
    
    return 0;
}

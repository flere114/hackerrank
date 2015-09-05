#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {
    // Complete this function
    vector <int> a,b;
    if(arr.size()<=1)   return;
    int p = arr[0];
    for(int i=1;i<arr.size();i++)
        if(arr[i] < p)  a.push_back(arr[i]);
        else    b.push_back(arr[i]);
    quickSort(a);
    quickSort(b);
    for(int i=0;i<a.size();i++)
        arr[i] = a[i];
    arr[a.size()] = p;
    for(int i=0;i<b.size();i++)
        arr[i+a.size()+1] = b[i];
    for(int i=0;i<arr.size();i++)
        if(i==0)    printf("%d",arr[i]);
        else    printf(" %d",arr[i]);
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    
    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    
    quickSort(arr);
    
    return 0;
}

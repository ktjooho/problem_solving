#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,d;
vector<int> a;
int main()
{
    scanf("%d",&n);
    a.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    scanf("%d",&m);
    for(int i=0; i<m; ++i){
        scanf("%d",&d);
        printf("%d ",binary_search(a.begin(), a.end(), d));
    }
    printf("\n");
    
    return 0;
}
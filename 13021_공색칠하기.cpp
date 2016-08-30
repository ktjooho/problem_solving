#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;
int n,m,l,r;
int check[2000];
set<int> s;
unsigned long long ans;


int main()
{
    ans = 1;
    
    cin>>n>>m;
   
    for(int i=1; i<=m; ++i)
    {
        cin>>l>>r;
        
        for(int j=l; j<=r;++j)
            check[j] = i;
    }
    
    for(int i=1; i<=n; ++i)
    {
        if(check[i]>0)
            s.insert(check[i]);
    }
    for(int i=0; i<s.size();++i)
        ans *= 2;
    
    printf("%llu\n",ans);
    
    return 0;
}
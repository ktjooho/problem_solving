#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int t,n,m,d;

int bs(int l, int h,int v,vector<int>&s)
{
    int mid = (l+h)/2;
    
    if(l>h)
        return 0;
    if(s[mid]==v)
        return 1;
    
    if(v < s[mid])
            return bs(l,mid-1,v,s);
    else
            return bs(mid+1,h,v,s);
        
    return 0;
}

int main()
{
    cin>>t;
    while (t--) {
        vector<int>s;
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&d);
            s.push_back(d);
        }
        sort(s.begin(), s.end());
        
        scanf("%d",&m);
        for(int i=0; i<m;++i){
            scanf("%d",&d);
            if(bs(0, n-1, d,s)) puts("1");
            else puts("0");
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,arr[301],dp[301][3];

int go(int i, int j)
{
    if(i<=0)
        return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    
    if(j==1)
        ans = go(i-1,2) + arr[i];
    else
        ans = max(go(i-2,2),go(i-2,1)) + arr[i];
    return ans;
}

int main()
{
    
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    cout<<max(go(n,1),go(n,2))<<endl;
    return 0;
}
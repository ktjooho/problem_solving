#include <iostream>
#include <cstring>
using namespace std;
#define MOD 10007
int n,dp[1001];

int go(int i)
{
    if(i<0)
        return 0;
    if(i==0)
        return 1;
    int& ans = dp[i];
    
    if(ans != -1) return ans;
    ans = 0;
    ans = go(i-2) + go(i-1);
    
    
    return ans%MOD;
    
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    cout<<go(n)<<endl;
    return 0;
}
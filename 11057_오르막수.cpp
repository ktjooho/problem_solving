#include <iostream>
#include <cstring>

#define MOD 10007
long long n,dp[1001][10],ans;
using namespace std;

long long go(int i, int j)
{
    if(i==1)
        return 1;
    
    long long& ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    
    for(int x=0; x<=j; ++x)
        ans = (ans + go(i-1,x)) % MOD;
    
    return ans;
}


int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0; i<10; ++i)
        ans = ans + go(n,i);
    cout<<ans%MOD<<endl;
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#define DIV 1000000007
int s,a,b,c;
long long dp[51][51][51][51];

using namespace std;

long long go(int _s, int i, int j, int k)
{
    if(_s==0)
    {
        if((i==0 && j==0)&&k==0)
            return 1;
        else
            return 0;
    }
        
    
    long long& ans = dp[_s][i][j][k];
    if(ans != -1) return dp[_s][i][j][k];
    ans = 0;
    
    
    if(i>0) ans += go(_s-1,i-1,j,k) % DIV;
    if(j>0) ans += go(_s-1,i,j-1,k) % DIV;
    if(k>0) ans += go(_s-1,i,j,k-1) % DIV;
    
    if(i>0 && j>0) ans += go(_s-1,i-1,j-1,k) % DIV;
    if(i>0 && k>0) ans += go(_s-1,i-1,j,k-1) % DIV;
    if(j>0 && k>0) ans += go(_s-1,i,j-1,k-1) % DIV;
    
    if((i>0 && j>0) && k>0)ans += go(_s-1,i-1,j-1,k-1) % DIV;
   // cout<<ans<<endl;
    return (ans % DIV);
    
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d%d",&s,&a,&b,&c);
    printf("%lld\n",go(s,a,b,c));
    return 0;
}
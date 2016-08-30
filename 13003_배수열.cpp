#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define DIV 1000000007

using namespace std;

int n,l;

long long dp[2005][2005];
int cache[2005][2005];

long long go(int prev,int len)
{
    if(len>l)
    {
        return 1;
    }
    
    long long& ans = dp[prev][len];
    
    if(ans != -1) return ans;
    
    ans = 0;
    
    for(int i=1; i<=cache[prev][0]; ++i)
    {
        ans = ((ans + go(cache[prev][i],len+1))%DIV);
        
    }
    return (ans % DIV);
}



int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d",&n,&l);
   // printf("%lld\n",go(1,1));
    
    for(int i=1; i<=n; ++i)
    {
        for(int j=i; j<=n; ++j){
            if(j%i==0){
                cache[i][0]++;
                cache[i][cache[i][0]] = j;
            }
        }
    }
    printf("%lld\n",go(1,1));
    /*
    for(int i=1; i<=l; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            for(int k=1; k<=cache[j][0]; ++k)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][k])%DIV;
            }
        }
    }
    */
    return 0;
}
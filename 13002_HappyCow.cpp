#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

//2000 * 1000 => 2백만

int n,h[2001],dp[2001][2001];

using namespace std;

int go(int i, int j,int d)
{
    if(i==j){
        return h[i]*d;
    }
    if(i>j)
        return 0;
    
    int& ans = dp[i][j];
    
    if(ans!=-1) return dp[i][j];
    
    ans = 0;
    
    ans = max(ans,go(i+1,j,d+1)+h[i]*d);
    ans = max(ans,go(i,j-1,d+1)+h[j]*d);
    
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d",&n);
    
    for(int i=0; i<n; ++i)
        scanf("%d",&h[i]);
    
    printf("%d\n",go(0,n-1,1));
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>

int rgb[3],ans;

using namespace std;
// R,G,B,

int dp[101][101][101];

int go(int i, int j, int k)
{
    if((i==0 && j==0) && k==0)
        return 0;
    
    int &ans = dp[i][j][k];
    
    if(ans != -1) return ans;
    
    ans = 1000;
    
    ans = min(ans, go(max(0,i-1),max(0,j-1),max(0,k-1))+1);
    ans = min(ans, go(max(0,i-3),j,k)+1);
    ans = min(ans, go(i,max(0,j-3),k)+1);
    ans = min(ans, go(i,j,(max(0,k-3)))+1);
    
    return ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d",&rgb[0],&rgb[1],&rgb[2]);
    printf("%d\n",go(rgb[0],rgb[1],rgb[2]));
    return 0;
}
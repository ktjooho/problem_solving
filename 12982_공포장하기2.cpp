#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>


long long dp[100001]; //남은 색의 갯수
int x[100001],k;

using namespace std;

int solve(int remainK)
{
    if(remainK==0)
        return 0;
    
    long long &ans = dp[remainK];
    
    if(ans!=-1) return ans;
    
    ans=0;
    
    for(int i=0; i<k; ++i)
    {
        if(x[i]>0){
            
            int n = x[i]
            
        }
    }
    
    
    
    return 1;
}

int back(int s){
    
    
}

int main()
{
    scanf("%d",&k);
    
    for(int i=0; i<k; ++i)
        scanf("%d",&x[i]);
    
    memset(dp, -1, sizeof(dp));
    
    
    
    
    return 0;
}
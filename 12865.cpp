#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

int N,W,K,V;

int dp[101][100001];
int w[100001];
int v[100001];
int s[100001];

using namespace std;

int main()
{
    scanf("%d%d",&N,&K);
    
    for(int i=0; i<N; ++i)
    {
        scanf("%d%d",&W,&V);
        
        w[i] = W;
        v[i] = V;
    }
    
    //정렬 불필요함.
    
    
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<=K; ++j)
        {
            if(w[i-1]<=j && dp[i-1][j] < dp[i-1][j-w[i-1]]+v[i-1])
                dp[i][j] = dp[i-1][j-w[i-1]]+v[i-1];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    printf("%d\n",dp[N][K]);
    return 0;
}
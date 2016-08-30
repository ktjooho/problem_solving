#include <cstdio>
#include <cstdlib>
#include <algorithm>

int N;
            // 연결된 정점, 최대 간선 그래프 정점, 연결 시킬 정점
int score[100],dp[100][100];

using namespace std;
int main()
{
    scanf("%d",&N);
    
    for(int i=1; i<N; ++i)
        scanf("%d",&score[i]);
    
    
    dp[2][1]=score[1]*2;
    dp[3][2] = dp[2][1] + score[1] + score[2] - score[1];
    
    
    for(int i=4; i<=N; ++i)
    {
        for(int j=2; j<=i-1;++j) // 최대 차수
        {
            int _max = -1;
            for(int k=1; (k<j && k<=i-j-1); ++k)
            {
                
                _max = std::max(_max,dp[i-1][j] +  score[1] + score[k+1] - score[k]);
                printf("[%d][%d]<= [%d][%d]=[%d] + [%d] \n",i,j,i-1,j,dp[i-1][j],score[1] + score[k+1] - score[k]);
                
            }
            if(j>2)
            {
                printf("[%d][%d] <= [%d][%d]\n",i,j,i-1,j-1);
                _max = std::max(_max,dp[i-1][j-1] + score[1] + score[j] - score[j-1]);
            }
            dp[i][j] = _max;
            printf("[%d][%d] = [%d]\n",i,j,dp[i][j]);
            
        }
    }
    
    int ans = 0;
    
    for(int i=1; i<=N-1; ++i)
        ans = std::max(ans,dp[N][i]);
    
    printf("%d\n",ans);
    
    return 0;
    
}

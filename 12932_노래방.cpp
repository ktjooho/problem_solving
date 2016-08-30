#include <cstdio>
#include <cstdlib>
#include <algorithm>

int n,song[2001],dp[2001][2001];

// 순차적으로 탐색
// [효빈][영선]
//
using namespace std;

int main()
{
    scanf("%d",&n);
    
    for(int i=1; i<=n;++i)
        scanf("%d",&song[i]);
    
    const int INF = 1000000;
    
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            dp[i][j] = INF;
    
    
       for(int j=1; j<=n;++j)
        {
            dp[2][j] = dp[2][j-1] + abs(song[j] - song[j-1]);
            dp[j][2] = dp[j-1][2] + abs(song[j] - song[j-1]);
            
        }
    
    // 효민이가 마지막으로 부른 음 ,, 영선이가 마지막으로 부른 음
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<i-1;++j) //바로 이전 단계에 있는 음악들.
        {
            //dp[i][?] => dp[i-1][x] + (song[i-1] - song[i])
            //dp[i][i-1] =>  dp[x][i-1] + (song[x] - song[i])
            
            //dp[?][i] => dp[x][i-1] + (song[i-1] - song[i])
            //dp[i-1][i] => dp[i-1][x] + (song[x] - song[i])
            
            if((i==1&&j==2) ||( j==1 && i==2))
            {
                ;
            }
            if(i==2)
            {
                
                
            }
            
            dp[i][j] = min(dp[i][j], dp[i-1][j] + (i == 1 ? 0 : abs(song[i-1]-song[i])));
            
            dp[i][i-1] = min(dp[i][i-1], dp[j][i-1]+ (j ? abs(song[j]-song[i]) : 0));
            
            dp[j][i] = min(dp[j][i], dp[j][i-1] + (i == 1 ? 0 : abs(song[i-1]-song[i])));
            
            dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + (j ? abs(song[j]-song[i]) : 0));
            
            
            
            // i-1 i
            //  영 효
            //  영 영
            //  효 효
            //  효 영
            //ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
            
            // dp[i][j] = dp[i-1][j] +  dp[j][i-1]
            
            // dp[j][i] = dp[j][i-1] + dp[i-1][j]
        }
    }
    
    for(int i=0;i<=n;++i)
    {
        for(int j=0; j<=n;++j)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
        
    }
    
    int ans = 100000;
    
    for(int i=1; i<n; ++i)
    {
        ans = min(dp[n][i],dp[i][n]);
        //dp[i][a] = dp[i-1]
        //dp[b][i]
    }
    printf("%d\n",ans);
    /*
     
     dp[영선이 가지는 음의 수][효빈이 가지는 음의 수] = 총
     
     */
    
    
    
    
    return 0;
}
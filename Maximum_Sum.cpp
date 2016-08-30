#include <cstdio>
#include <cstdlib>
#include <algorithm>


#define SIZE_N 200

int board[SIZE_N][SIZE_N],N;

int solve()
{
    int globalMax=-127*100,sum=0,localMax;
    
    for(int i=1; i<=N; ++i)
    {
        for(int j=i; j<=N; ++j)
        {
            sum = 0;
            localMax = -127*100;
            
            for(int k=1; k<=N;++k)
            {
                sum = std::max(sum,0) + board[j][k] - board[i-1][k];
                localMax = std::max(sum, localMax);
            }
            
            globalMax = std::max(globalMax,localMax);
        }
    }
    return globalMax;
}

int main()
{
    scanf("%d",&N);
    
    for(int i=1; i<=N;++i)
    {
        for(int j=1; j<=N; ++j)
        {
            scanf("%d",&board[i][j]);
            if(i>2)
                board[i][j] = board[i-1][j] + board[i][j];
        }
    }
    printf("%d\n",solve());
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define INF 1000000

int g[55][55];

int n,potion,cost[55],visitCnt;

int visit[55],dist[55],prev[55];

int back[55],numPath;

float ans;

void find(int visit)
{
    if(visit==-1 || visit==0)
        return ;
    cost[visitCnt++] = g[prev[visit]][visit];
    find(prev[visit]);
}

using namespace std;

int main()
{
    scanf("%d%d",&n,&potion);
    
    memset(prev, -1, sizeof(prev));
    
    for(int i=0; i<=n; ++i)
        for(int j=0;j<=n;++j)
            g[i][j] = INF;
    
    getchar();
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char c;
            scanf("%c",&c);
            g[i][j] = c - '0';
        }
        getchar();
    }
    
    
    for(int i=0; i<n;++i)
        dist[i] = INF;
    
    dist[0]=0;
    
    
    
    for(int i=0; i<n; ++i)
    {
        int u=-1;
        int _min=INF;
        
        for(int j=0; j<n; ++j)
        {
            if(dist[j]<_min && !visit[j]){
                _min = dist[j];
                u = j;
            }
        }
        if(u==-1) break;
        visit[u] = 1;
        
        
        for(int k=0; k<n; ++k)
        {
            if(k==1)
                back[numPath++] = u;
            else if(dist[k] > dist[u]+g[u][k])
            {
                dist[k] = dist[u]+g[u][k];
                prev[k] = u;
            }
            
        }
    }
    float ans = 100.0f;
    for(int i=0; i<numPath; ++i,visitCnt=0)
    {
   
        cost[visitCnt++]=g[back[i]][1];
        find(back[i]);
        
        for(int j=0; j<visitCnt-1; ++j)
        {
            for(int k=j; k<visitCnt;++k)
            {
                if(cost[j]<cost[k])
                {
                    int temp = cost[j];
                    cost[j] = cost[k];
                    cost[k] = temp;
                }
            }
        }
        
        float val=0.0;
        
        for(int j=0,k=potion; j<visitCnt; ++j,--k)
        {
            if(k>0)
                val += ((float)cost[j] / 2.);
            else
                val += cost[j];
        }
        if(ans>val)
            ans = val;
    }
    printf("%.9f\n",ans);
    return 0;
    
}
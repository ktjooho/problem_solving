#include <cstdio>
#include <cstdlib>

#define INF 100000
#define MAX_SIZE 30

unsigned long long w[2][MAX_SIZE][MAX_SIZE],dist[3][MAX_SIZE],visit[MAX_SIZE],ans;
int n;
char buf[MAX_SIZE];


int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<2;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
                w[i][j][k]=INF;
    
    for(int i=0; i<2; ++i)
    {
        for(int k=0; k<n; ++k)
        {
            scanf("%s",buf);
            for(int j=0; j<n;++j)
            {
                if(buf[j]=='.')
                    w[i][k][j] = INF;
                else
                    w[i][k][j]= (buf[j]-'0');
            }
        }
    }

    
    for(int k=0;k<3;++k)
    {
        for(int i=0;i<n;++i)
        {
            dist[k][i]=INF;
            visit[i]=0;
        }
    }
    dist[0][0]=dist[1][0]=dist[2][0]=0;
    
    for(int i=0;i<n;++i)
    {
        int u =-1;
        unsigned long long _min = INF;
        
        for(int k=0; k<n;++k)
        {
            if(dist[2][k]<_min && !visit[k]){
                _min = dist[2][k];
                u = k;
            }
        }
        if(u==-1) break;
        visit[u] = 1;
        
        for(int k=0; k<n;++k)
        {
            unsigned long long  d = (dist[1][u]+w[1][u][k])*(dist[0][u] + w[0][u][k]);
            
            if(dist[2][k] > d)
            {
                dist[2][k] = d;
                dist[1][k] = dist[1][u] + w[1][u][k];
                dist[0][k] = dist[0][u] + w[0][u][k];
            }
            
        }
    }
    if(dist[2][1]==INF)
        printf("-1\n");
    else
        printf("%llu\n",dist[2][1]);
    return 0;
}
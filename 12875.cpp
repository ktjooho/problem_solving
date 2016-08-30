#include <cstdio>
#include <cstdlib>
#include <cstring>


#define INF 2000000

int g[55][55];
char buf[55];
int D,N,result;

int main()
{
    scanf("%d",&N);
    scanf("%d",&D);
    result = -1;
    
    for(int i=0; i<N; ++i)
    {
        scanf("%s",buf);
        for(int j=0; j<N;++j){
            if(buf[j]=='Y')
                g[i][j]=1;
            else
                g[i][j]=INF;
        }
        
        g[i][i]=0;
    }
    
    for(int k=0; k<N; ++k)
    {
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                
                if(g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(result < g[i][j])
                result = g[i][j];
        }
    }
    
    if(result == INF)
        printf("-1\n");
    else
        printf("%d\n",result*D);
    
    
    
    return 0;
}
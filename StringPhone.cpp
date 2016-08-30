#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define WHITE 2
#define GRAY 1
#define BLACK 0

using namespace std;

int T,N,M,i,j,k,x,y,n,s,t,d,c[3010][4][3],e[3010][3010],v[3010];

bool bConn;

int main()
{
    scanf("%d",&T);

    while (T--)
    {
        scanf("%d",&N);
       // memset(e, 0, sizeof(e));
        
        for(i=1; i<=N;++i)
        {
            v[i]=0;
            scanf("%d%d",&x,&y);
            for(j=0; j<2; ++j)
                for(k=0; k<2; ++k)
                    c[i][j*2+k][0] = x+j,c[i][j*2+k][1]=y+k,c[i][j*2+k][2]=GRAY;
            for(j=1; j<=N;++j)
                e[i][j]=0;
        }
        //
        // N * 9 = 90909099
        
        scanf("%d",&M);
        
        for(i=0;i<M;++i)
        {
            scanf("%d%d%d",&s,&t,&d);
            e[s][t]=d;
            e[t][s]=d;
        }
        
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            n = q.front();
            
            q.pop(); v[n]=1;
            
            for(i=1; i<=N; ++i)
            {
                bConn = false;
                
                if(e[n][i] && !v[i])
                {
                    for(j=0; j<4; ++j)
                    {
                        for(k=0; k<4; ++k)
                        {
                            if(c[n][j][2]==WHITE || c[i][k][2]==WHITE)
                                continue;
                           
                            d = abs(c[n][j][0]-c[i][k][0]) + abs(c[n][j][1]-c[i][k][1]);
                            
                            if(d==e[n][i])
                            {
                                bConn=true;
                                c[n][j][2] = c[i][k][2] = BLACK;
                            }
                        }
                    }
                    for(j=0;j<4;++j)
                    {
                        if(c[n][j][2]!=WHITE)
                            c[n][j][2]++;
                        if(c[i][j][2]!=WHITE)
                            c[i][j][2]++;
                    }
                    if(bConn)
                        q.push(i);
                }
            }
            for(i=1; i<=N; ++i)
            {
                if(e[n][i] && !v[i])
                {
                    for(j=0;j<4; ++j)
                    {
                        for(k=0;k<4;++k)
                        {
                            if(c[n][j][2]==WHITE || c[i][k][2]==WHITE)
                                continue;
                            d = abs(c[n][j][0]-c[i][k][0]) + abs(c[n][j][1]-c[i][k][1]);
                            if(d==e[n][i])
                                c[n][j][2] = c[i][k][2] = BLACK;
                        }
                    }
                    for(j=0;j<4;++j)
                    {
                        if(c[n][j][2]!=WHITE)
                            c[n][j][2]++;
                        if(c[i][j][2]!=WHITE)
                            c[i][j][2]++;
                    }

                }
            }
        }
        
        
        bConn = true;
        
        
        for(i=1; i<=N;++i)
        {
            n=0;
            for(j=0;j<4;++j)
                if(c[i][j][2]!=WHITE)
                    ++n;
            if(!n)
            {
                bConn=false;
                break;
            }
        }
        if(bConn)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}
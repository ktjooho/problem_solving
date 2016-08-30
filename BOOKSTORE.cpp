#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int C,N,M,i,j,k,r,b[210][210][2],c[210][2],ret,min;

int main()
{
    scanf("%d",&C);
    
    while (C--)
    {
        scanf("%d%d",&N,&M);
        memset(c, 0, sizeof(c));
        
        for(i=1;i<=N;++i)
            for (j=1;j<=M;++j)
                scanf("%d%d",&b[i][j][0],&b[i][j][1]);
        for(i=1; i<=M; ++i)
            for (j=1; j<N; ++j)
                for(k=j+1;k <=N;++k)
                    if(b[j][i][1] < b[k][i][1])
                    {
                        int t0 = b[k][i][0];
                        int t1 = b[k][i][1];
                        
                        b[k][i][0] = b[j][i][0];
                        b[k][i][1] = b[j][i][1];
                        
                        b[j][i][0] = t0;
                        b[j][i][1] = t1;
                    }
        
        ret = 10000 * 200;

        for (i=1;i<=M; ++i)
        {
            int ci=0;
            min=b[1][i][0];
            
            for(j=2;j<=N;++j)
            {
                ci = b[j][i][0]+ci-b[j-1][i][1];
                if(ci > 0)
                {
                    min += ci;
                    ci=0;
                }
            }
            if(min < ret)
                ret = min;
        }
        printf("%d\n",ret);
    }
    return 0;
}
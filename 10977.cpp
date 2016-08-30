#include <cstdio>

int M,N,T,i,j,hm,result;
int v[2][1000100];


int main()
{
    
    scanf("%d",&T);
    
    while (T-->0)
    {
        scanf("%d%d",&M,&N);
        
        for(int i=0; i<=M; ++i)
            v[1][i] = 0;
        
        for(int i=0; i<N; ++i)
        {
            scanf("%d",&v[0][i]);
            v[1][v[0][i]] = 1;
        }
        
        hm = M/2;
        result = M;
        
        for(i=1; i<=hm; ++i)
        {
            if(M%i==0)
            {
                int n;
                
                for(j=0; j<N; ++j)
                {
                    n = (v[0][j] + i -1) % M  + 1;
                    if(!v[1][n])
                        break;
                }
                if(j==N)
                {
                    result = i;
                    break;
                }
            }
            
        }
        printf("%d\n",result);
    }
    return 0;
}

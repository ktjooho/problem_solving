#include <cstdio>

#define MAX 210

typedef unsigned short US;

int nCase, N, M,i,j,k;

US input[MAX];

int c[MAX][16];

int main()
{
    scanf("%d",&nCase);
    while (nCase--)
    {
        scanf("%d%d",&N,&M);
        for(i=1; i<=N;++i)
        {
            scanf("%d",&input[i]);
            US cmp = 0x1;
            for(j=0; j<16; ++j,cmp<<=1)
            {
                c[i][j] = c[i-1][j]+((input[i]&cmp)?1:0);
                if(i==N && c[N][j]<M)
                    for(k=1; k<=N; ++k)
                        c[k][j]=0;
            }
        }
        //ALGORITHM
        
        printf("%d\n",0);
    }
    // insert code here...
    return 0;
}
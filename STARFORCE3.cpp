#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
using namespace std;


int main()
{
    int nCase,N,M,input[210],c[100000],e,n,max,bn;
    
    scanf("%d",&nCase);
    while (nCase--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d%d",&N,&M);
        for(int i=0; i<N; ++i)
            scanf("%d",&input[i]);
        for(int i=0; i<=65535; ++i)
        {
            n=0,e=0;
            for(int j=0; j<N;++j)
            {
                e |= input[j];
                if(!((e&i)-i))
                {
                    e=0;
                    ++n;
                }
            }
            if(n>=M)
                c[i]=1;
        }
        max = -1;
        for(int i=0; i<=65535; ++i)
        {
            if(c[i])
            {
                bn = bitset<16>(i).count();
                if(bn > max)
                    max = bn;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
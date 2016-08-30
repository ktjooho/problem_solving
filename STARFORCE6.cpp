#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

unsigned short N,M,nCase,OR[210][210],t[210][210],c[210][16];

int main()
{
    scanf("%hd",&nCase);
    
    while (nCase--)
    {
        
        scanf("%hd%hd",&N,&M);
        
        memset(OR, 0, sizeof(OR));
        
        memset(t, 0, sizeof(t));
        
        for(int i=1; i<=N; ++i)
        {
            scanf("%hd",&OR[i][i]);
            for(int j=i-1; j>=1; --j)
                OR[j][i] = OR[j+1][i] | OR[j][j];
            unsigned short cmp = 0x1;
            for(int j=0; j<16; ++j,cmp<<=1)
                c[i][j] = c[i-1][j] + ((OR[i][i]&cmp)?1:0);
            
        }
        
        t[0][0] = 65535;
        
        for(int i=1; i<=M; ++i)
        {
            int l = N-M+i-1;
            
            if(i==1) l = 0;
            
            //prev
            for(int j=i-1; j <= l; ++j)
            {
                int nl = N-M+i;
                
                //cur
                for(int k=j+1; k<=nl; ++k)
                {
                    unsigned short val = t[i-1][j] & OR[j+1][k];
                    if(bitset<16>(val).count() > bitset<16>(t[i][k]).count())
                        t[i][k] = val;
                }
            }
        }
        printf("%d\n",bitset<16>(t[M][N]).count());
    }
    return 0;
}
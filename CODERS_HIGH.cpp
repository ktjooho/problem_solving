#include <cstdio>
#include <cstdlib>


int Q,p,equationNum;
long long eq[200100][2],x;


void makeTest()
{
    
    Q = 200000;

    int a,b;
    
    a=0,b=0;
    
    for(int i=0; i < 200000; ++i)
    {
        a += 2;
        b += 3;
        
    
        
    }
    
    
}
int main()
{
    scanf("%d",&Q);
    
    equationNum = 0;
    
    for(int i=0; i<Q; ++i)
    {
        scanf("%d",&p);
        
        
        if(p==1)
        {
            
            scanf("%lld%lld",&eq[equationNum][0],&eq[equationNum][1]);
            
            equationNum++;
        }
        else
        {
            scanf("%lld",&x);
            
            long long maxY = -8223372036854775807LL;
            long long val;
            
            for(int i=0; i< equationNum; ++i)
            {
                val = eq[i][0]*x + eq[i][1];
                
                if(maxY < val)
                    maxY = val;
            }
            
            printf("%lld",maxY);
        }
    }
    return 0;
}
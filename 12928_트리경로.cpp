#include <cstdio>
#include <cstdlib>

int n,s,table[51][1001];

int main()
{
    
    table[3][2] = 1;
    table[3][1] = 0;
    
    scanf("%d%d",&n,&s);
    
    if(s < n-2)
    {
        
    }
    // 차수 [3] +
    for(int i=4; i<=50; ++i)
    {
        
        table[i][j] = table[i-1][j] +
        
        /*
        for(int j=1; j<1000; ++j)
        {
            
            
            
        }
         */
    }
    
    
    
    return 0;
}
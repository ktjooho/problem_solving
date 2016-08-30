#include <cstdio>
#include <cstdlib>


#define V_SIZE 8

#define INF 2500000000

int xs,ys,xe,ye;
unsigned long long  xy[8][2];
unsigned long long g[V_SIZE][V_SIZE];

int main()
{
    scanf("%llu%llu",&xy[0][0],&xy[0][1]);
    scanf("%llu%llu",&xy[1][0],&xy[1][1]);
 
    for(int i=0;i<V_SIZE; ++i)
    {
        for(int j=0; j<V_SIZE; ++j)
            g[i][j] = INF;
        g[i][i] = 0;
    }
    
    for(int i=0; i<3; ++i)
    {
        int s = 2 + i*2;
        scanf("%llu%llu%llu%llu",&xy[s][0],&xy[s][1],&xy[s+1][0],&xy[s+1][1]);
        g[s][s+1] = 10;
        g[s + 1][s] = 10;
    }
    
    //0,1
    //2,3
    //4,5
    //6,7
    
    for(int i=0; i<V_SIZE;++i){
        for(int j=0; j<V_SIZE; ++j){
            if(g[i][j]==INF){
                g[i][j] = abs(xy[i][0]-xy[j][0]) + abs(xy[i][1]-xy[j][1]);
            }
        }
    }
    
    for(int k=0; k<V_SIZE; ++k)
    {
        for(int i=0;i<V_SIZE;++i)
        {
            for(int j=0; j<V_SIZE; ++j)
            {
                if(g[i][j] > g[i][k] + g[k][j])
                {
                    //printf("[%llu][%llu](%llu) = [%llu][%llu](%llu) [%llu][%llu](%llu)\n",i,j,g[i][j],i,k,g[i][k],k,j,g[k][j]);
                    g[i][j] = g[i][k] + g[k][j];
                    
                }
            }
        }
    }
     //       printf("[%llu]->[%llu] = [%llu]\n",i,j,g[i][j]);
//    printf("========\n");
//    for(int i=0;i<V_SIZE;++i)
//        for(int j=0; j<V_SIZE;++j)
//            printf("[%llu]->[%llu] = [%llu]\n",i,j,g[i][j]);
//    
    
    printf("%llu\n",g[0][1]);
    
    
    
    
    
    
    
    return 0;
}
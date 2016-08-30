#include <cstdio>
#include <cstdlib>


#define INF 1000000007
#define MAX_SIZE 101

struct Edge {
    int from,to,cost;
};

int n,m,g[MAX_SIZE][MAX_SIZE],parade[MAX_SIZE][MAX_SIZE];
Edge road[2001];

using namespace std;

void floyd(int (*m)[MAX_SIZE])
{
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(m[i][j] > m[i][k] + m[k][j])
                    m[i][j] = m[i][k] + m[k][j];
    
}
void printG(int (*m)[MAX_SIZE])
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
        
    }
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            parade[i][j]=g[i][j] = INF;
            parade[j][i]=g[j][i] = INF;
        }
        parade[i][i]=g[i][i] = 0;
    }
    
    for(int i=0; i<m;++i)
    {
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        g[from][to] = cost;
        g[to][from] = cost;
        road[i] = {from,to,cost};
    }
    
//    printf("============\n");
    floyd(g);
//    printG(g);
//    printf("비교시작==\n");
    for(int i=0; i<m; ++i)
    {
        int nRoad = 0;
        int cost = road[i].cost;
        road[i].cost = INF;
        
        for(int j=0;j<n;++j)
        {
            for(int k=0; k<n; ++k)
            {
                parade[j][k] = INF;
                parade[k][j] = INF;
            }
            parade[j][j]=0;
        }
//        printG(parade);
        for(int j=0; j<m; ++j)
        {
            parade[road[j].from][road[j].to] = road[j].cost;
            parade[road[j].to][road[j].from] = road[j].cost;
        }
        
//        printG(parade);
//        printf("============\n");
        
        //Graph
        floyd(parade);
//        printG(parade);
        
        //원본과 비교
        for(int j=0; j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                if(g[j][k] < parade[j][k])
                {
//                    printf("[%d][%d]// [%d] < [%d]\n",j,k,g[j][k],parade[j][k]);
                    nRoad++;
                }
            }
        }
        
        //카운팅
        road[i].cost = cost;
        //출력
        printf("%d ",nRoad/2);
    }
    printf("\n");
    
    
    return 0;
}
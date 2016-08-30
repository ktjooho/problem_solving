#include <cstdio>

#define MAXN 100001
#define SZ 500
#define GROUP_NUM (MAXN/SZ)

int N,M,S[MAXN],V[MAXN],G[GROUP_NUM],E[MAXN];

int MIN_ARR[GROUP_NUM];
int MAX_ARR[GROUP_NUM];


int main()
{
    scanf("%d%d",&N,&M);
    
    int gn = N / SZ;
    
    for(int i=0; i<gn; ++i)
    {
        S[i] = -1;
        MIN_ARR[i] = 1000000000;
        MAX_ARR[i] = 0;
    }
    
    for(int i=0; i<M; ++i)
        scanf("%d",&V[i]);
    
    for(int i=0;i<N; ++i)
    {
        G[i] /=SZ;
        
        if(S[G[i]]==-1) S[G[i]] = i;
        
        E[G[i]] = i;
        
        if(MIN_ARR[G[i]] > V[i]) MIN_ARR[G[i]] = V[i];
        
        if(MAX_ARR[G[i]] < V[i]) MAX_ARR[G[i]] = V[i];
        
    }
    
    for(int i=0; i<M; ++i){
        
        int a,b;
        
        scanf("%d%d",&a,&b);
        
        int aGroup = G[a];
        int bGroup = G[b];
        
        
        //같은 그룹에 들어갈 경우
        //서로 다른 그룹 일 경우
        
        
        
        
    }
    return 0;
}
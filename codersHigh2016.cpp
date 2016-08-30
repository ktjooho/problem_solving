#include <cstdio>
#include <cstdlib>
#include <algorithm>

int N,M;
int A[1001];

int solve(int idx,int val)
{
    if(idx >= N)
        return val;
    
    int result = 0;
    
    for(int i=0; i<N; ++i)
    {
        printf("IDX[%d], VAL[%d], A[%d]\n",idx,val,A[i]);
        result += solve(idx+1, val*A[i]);
    }
    
    
    return result;
}


int main()
{
    scanf("%d%d",&N,&M);
    
    for(int i=0; i<M;++i)
        scanf("%d",&A[i]);
    
    printf("%d\n",solve(0,1));
    
    
    return 0;
}
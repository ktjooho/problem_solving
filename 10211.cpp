#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

int N,X[1001],T;

int solve()
{
    int maximum=-1500,sum=0;
    
    
    for(int i=0; i<N;++i)
    {
        
        // 모두 다 음수일경우 처리해야됨.
        // 양수가 하나있을 경우 0으로 셋팅해서도 되지만, 모두 다 음수일경우는 코드가 좀 달라야됨
        
        // maximum < 0, sum이 한번이라도 양수가 나오면 0 조건
        
        
        sum = std::max(0,sum) + X[i];
        
        maximum = std::max(sum, maximum);
        
    }
    return maximum;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&N);
        
        for(int i=0; i<N; ++i)
            scanf("%d",&X[i]);
        
        printf("%d\n",solve());
        
    }
    
    return 1;
}
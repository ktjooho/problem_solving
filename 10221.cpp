#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define DIV 1000000007

int N,D,T,v[1005][2],vv[1005][2];
unsigned long long dp[1001][2005];

using namespace std;

inline int GET_IDX(int idx)
{
    if(idx < 0)
        return idx * -1 + 1000;
    
    return idx;
}

inline unsigned long long getMatrixSum(int ps, int pt, int s, int t, int v, int dpIdx, int maximum)
{
    int ROW = pt - ps + 1;
    int COL = t - s  + 1;
    int start = s + ps - 1;
    
    int idx = v - start;
    int s0 = max(v - start -COL,0)+1;
    int s1 = s0;
    
    if( s0 > 1)
        idx = COL;
    else
        idx = v - start;
    
    s1 = s1 + min(idx-1, ROW-s0);
    
    s0 += (ps-1);
    s1 += (ps-1);
    s1 = min(s1,maximum);

    unsigned long long  n = dp[dpIdx][s1];
    unsigned long long  p = dp[dpIdx][s0-1];
    
    if(s0-1<=0)
        p = 0;
    
    return (n-p)%DIV;
}
unsigned long long getDP(int maximum)
{
    unsigned long long sum = 0;
    int ps,pt,s,t;
    int gs,gt;
    
    memset(dp, 0, sizeof(dp));
    
    s = v[0][0];
    t = v[0][1];
    
    ps = s;
    pt = t;
    
    for(int i=s; i<=min(t,maximum); ++i)
        dp[0][GET_IDX(i)]=1;
    
    for(int i=1; i<N; ++i)
    {
        unsigned long long mi = 0;
        
        while(ps<=0)
        {
            mi = (mi + dp[i-1][GET_IDX(ps)])%DIV;
            ++ps;
        }
        //이전 n-1 인덱스에서 sum이 음수값이 나오는 경우 처리.
        for(int j=ps; j<min(pt,maximum); ++j)
            dp[i-1][j+1] = (dp[i-1][j+1] + dp[i-1][j])%DIV;

        s = v[i][0];
        t = v[i][1];
        
        gs = vv[i][0];
        gt = vv[i][1];
        
        for(int v=gs; v<=min(gt,maximum); ++v)
            dp[i][GET_IDX(v)] = (dp[i][GET_IDX(v)] + mi)%DIV;

        int start = gs + ps;
        int end = gt + pt ;
        
        //이전 n-1 인덱스에서 sum이 양수값이 나오는 경우 처리
        for(int v=start; v<=min(end,maximum); ++v)
            dp[i][GET_IDX(v)] =  (dp[i][GET_IDX(v)] + getMatrixSum(ps, pt, gs, gt, v,i-1,maximum))%DIV;
        ps = s;
        pt = t;
    }
    
    // Get Sum
    for(int idx=v[N-1][0]; idx<=maximum; ++idx)
        sum += (dp[N-1][GET_IDX(idx)])%DIV;
    
    return sum;
}
int main()
{
    scanf("%d",&T);
    
    while (T--)
    {
        scanf("%d%d",&N,&D);
        
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&v[i][0],&v[i][1]);
            
            vv[i][0] = v[i][0];
            vv[i][1] = v[i][1];
            
            if(i>0)
            {
                v[i][0] = max(v[i][0] + v[i-1][0],v[i][0]);
                v[i][1] = max(v[i][1] + v[i-1][1],v[i][1]);
            }
            
        }
        unsigned long long DV,DV_1;
        
        DV = getDP(D);
        DV_1 = getDP(D-1);
        printf("%llu\n",((DV-DV_1)%DIV));
        
    }
    return 0;
}
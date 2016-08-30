#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MIN_VALUE -1000000
#define DIV 1000000007

int N,D,T,v[1005][2],vv[1005][2];

unsigned long long dp[1001][2005];

inline int GET_IDX(int idx)
{
    if(idx < 0)
    {
        
        return idx * -1 + 1000;
    }
    /*
    if(idx < 0 || idx > 2001)
    {
        printf("FUCK! IDX[%d]\n",idx);
    }
     */
    return idx;
}

using namespace std;
inline unsigned long long testSum(int ps, int pt, int s, int t, int v, int dpIdx, int maximum)
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
    
    //0 1 2 3 4 ... 1001
    //1 2 3 4 ....  1002
    //2 3 4 5 ....
    //2999 .....    4000
    
    /*
    for(int i=s0; i<=s1; ++i)
        printf("[%d],",i);
    printf("\n");
    */
    /*
    if(s1 < s0)
    {
        while (1) {
            printf("[%d[\n",s0);
        }
    }
     */
    /*
    if(s1 > maximum && dp[dpIdx][s1]>0)
    {
        printf("S1[%d] DP[%d][%d] = [%d]\n",s1,dpIdx,s1,dp[dpIdx][s1]);
    }
    */
    
    s1 = min(s1,maximum);
    unsigned long long  n = dp[dpIdx][s1];
    unsigned long long  p = dp[dpIdx][s0-1];
    
    /*
    
    if(s0 > 3)
    {
        
        printf("S1[%d]\n",s1);
    }
    */
    
    if(s0-1<=0)
    {
      //  printf("N[%d] P[%d]\n",s1,s0);
        p = 0;
     //   printf("FUCK");
    }
    
   // printf("V[%d] D[%d] - D[%d] = %d\n",v,s1,s0-1,n-p);
    
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
          // printf("I[%d] PS[%d], mi[%d]\n",i,ps,mi);
           ++ps;
        }
        
        //  1000  + -1000(다음) <= 1000
        // -999 1000
      //  int qt = min(1000,pt);
        
        
        for(int j=ps; j<min(pt,maximum); ++j)
        {
            dp[i-1][j+1] = (dp[i-1][j+1] + dp[i-1][j])%DIV;
            //  printf(" DP[%d][%d] = [%d]\n",i-1,j+1,dp[i-1][j+1]);
        }
        /*
        for(int v=-1000; v<=1000; ++v)
        {
            if(dp[i][GET_IDX(v)]!=0)
            {
                printf("NEXT DP[%d][%d]=[%d]\n",i,v,dp[i][GET_IDX(v)]);
            }
        }
         */
        //s = min(v[i][0],maximum);
        //t = min(v[1][1],maximum);
       // s = min(v[0][0],maximum);
       // t = min(v[0][1],maximum);
        
        s = v[i][0];
        t = v[i][1];
        
     //   printf("PS[%d] PT[%d] S[%d] T[%d] \n",ps,pt,s,t);
        
        gs = vv[i][0];
        gt = vv[i][1];
        
 
        
        
        for(int v=gs; v<=min(gt,maximum); ++v)
        {
          ////  if(v > maximum)
             //   break;
            //printf(">>>DP[%d][%d]=[%d]\n",i,v,dp[i][GET_IDX(v)]);
            dp[i][GET_IDX(v)] = (dp[i][GET_IDX(v)] + mi)%DIV;
           /*
            if(GET_IDX(v)<1000 && GET_IDX(v) > maximum)
            {
                printf("SUCKLY [%d]\n",v);
            }
            */
          //  printf("!!!DP[%d][%d]=[%d]\n",i,v,dp[i][GET_IDX(v)]);
        }
        //
       // int temp = dp[i-1][0];
       // dp[i-1][0] = 0;
        
        int start = gs + ps;
        int end = gt + pt ;
        
        for(int v=start; v<=end; ++v)
        {
            if(v > maximum)
                break;
           // printf("PREV DP[%d][%d]=%d, ",i,v,dp[i][GET_IDX(v)]);
            dp[i][GET_IDX(v)] =  (dp[i][GET_IDX(v)] + testSum(ps, pt, gs, gt, v,i-1,maximum))%DIV;
            
            /*
            if(GET_IDX(v)<1000 && GET_IDX(v) > maximum)
            {
                printf("ssSUCKLY [%d]\n",v);
            }
             */
            
           // printf("** DP[%d][%d] = %d\n",i,v,dp[i][GET_IDX(v)]);
        }
         
        ps = s;
        pt = t;
    }
    
    // Get Sum
    for(int idx=v[N-1][0]; idx<=maximum; ++idx)
    {
       // printf("[IDX : %d] dp[N-1][%d] = [%d]\n",idx,idx,dp[N-1][GET_IDX(idx)]);
        sum += (dp[N-1][GET_IDX(idx)])%DIV;
    }
    
    return sum;
}
int getDP2(int maximum)
{
    int sum = 0;
    int s,t;
    
    
    memset(dp, 0, sizeof(dp));
    
    s = min(v[0][0],maximum);
    t = min(v[0][1],maximum);
    
    
    for(int i=s; i<=t; ++i)
    {
        dp[0][GET_IDX(i)]=1;
        // x<=0 일떄
        // x>0 일때
    }
    
    
    for(int i=0; i<N-1;++i)
    {
        //덧셈 규칙이있다.
        for(int k=min(v[i][0],v[i][0]); k<=min(v[i][1],v[i][1]);++k)
        {
            //printf("V[%d][%d]=[%d]\n",i,1,v[i][1]);
            for(int j=vv[i+1][0]; j<=vv[i+1][1]; ++j)
            {
                int s = GET_IDX(k);
                
                /*
                if( k > maximum)
                    continue;
                */
                
                
                int t = GET_IDX(max(0,k)+j);
                
                if(max(0,k)+j <= maximum)
                {
                    /*
                    if((k > maximum) && dp[i][s] )
                    {
                        printf("k[%d] j[%d], dp[%d] \n",k,j,dp[i][s]);
                    }
                    */
                    if(s > 2000)
                    {
                        printf("S[%d]k[%d] dp[%d]\n",s,k,dp[i][s]);
                    }
                    dp[i+1][t] = (dp[i+1][t] + dp[i][s]);
                 //   printf("DP[%d][%d]=[%d]\n",i+1,t,dp[i+1][t]);
                }
            }
        }
    }
    
    // Get Sum
    for(int idx=v[N-1][0]; idx<=maximum; ++idx)
    {
         //printf("[IDX : %d] dp[N-1][%d] = [%d]\n",idx,idx,dp[N-1][GET_IDX(idx)]);
        sum += (dp[N-1][GET_IDX(idx)])%DIV;
    }
    
    return sum;
}
int main()
{
    /*
    while (1) {
        int ps,pt,s,t,v;
        scanf("%d%d%d%d%d",&ps,&pt,&s,&t,&v);
        testSum(ps, pt, s , t,v,1,2);
    }
    */
    
    
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
     
        //DV = getDP2(D);
        //DV_1 = getDP2(D-1);
//        
        //printf("%llu\n",((DV-DV_1)%DIV));
      
//        
        DV = getDP(D);
        DV_1 = getDP(D-1);
        printf("%llu\n",((DV-DV_1)%DIV));
        
    }

    
    return 0;
    
}
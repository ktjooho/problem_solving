#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <cstring>


char g[20][20];
long long d[16][1<<16];
int n,setArr[16][1<<16];
using namespace std;

long long solve(int check, int s)
{
    long long& ans = d[check][s];
    
    if(ans != -1) return ans;
    
    ans = 0;
    
    int bitCnt = bitset<16>(s).count();
    
    if(bitCnt==1)
        return ans=1;
    
    int s1 = 1<<check;
    int s2;
    
    for(int i=0; i<n;++i){
        
        if(g[check][i]=='N')
            continue;
        
        s2 = 1<<i;
        
        if(!(s2 & s))
            continue;
        
        int nextBitCnt = bitCnt>>1;
        
        for(int j=1; j<=setArr[nextBitCnt][0];++j)
        {
            int bit = setArr[nextBitCnt][j];
            
            if((bit&s) != bit)
                continue;
            
            int s1_bit = bit;
            int s2_bit = s & ~bit;
            
            if( (s1_bit&s1) && (s2_bit&s2))
                ans += 2 * solve(check, s1_bit) * solve(i,s2_bit);
        }
    }
    return ans;
}

void makeSum(int n,int sum, int dim)
{
    if(n<=0)
    {
        setArr[dim][0]++;
        setArr[dim][setArr[dim][0]] = sum;
        return ;
    }
    //1. 포함
    makeSum(n-1, sum | 1<<(n-1),dim+1);
    //2. 미포함
    makeSum(n-1,sum,dim);
}
int main()
{
    scanf("%d",&n);
    
    makeSum(n, 0,0);
    
    for(int i=0;i<n;++i)
        scanf("%s",g[i]);
        
    memset(d,-1,sizeof(d));
    for(int i=0; i<n; ++i)
        cout<<solve(i, (1<<n)-1)<<' ';
        //printf("%lld ",solve(i, (1<<n)-1));
    cout<<endl;
    return 0;
}
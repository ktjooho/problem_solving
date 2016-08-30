#include <cstdio>

int n,b[51];

int solve()
{
    int ans=0;
    int check=0;
    int cnt_1=0;
    
    
    for(int i=0;i<n;++i)
    {
        check+=b[i];
        
        if(b[i]%2)
        {
            cnt_1++;
            b[i]-=1;
        }
    }
    
    if(!check)
        return 0;
    
    if(cnt_1>0){
        ans += cnt_1;
    }else{
        for(int i=0; i<n; ++i)
            b[i]/=2;
        ans ++;
    }
        
    return ans + solve();
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    
    printf("%d\n",solve());
    return 0;
}
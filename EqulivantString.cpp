#include <cstdio>
#include <cstdlib>
#include <cstring>

char a[2][200001];
int cnt[2][200001];

int solve(int a_l, int a_r, int b_l, int b_r)
{
    int ans=1;
    int len = a_r - a_l + 1;
    
    
    if(cnt[0][a_r]-cnt[0][a_l-1] != cnt[1][b_r]-cnt[1][b_l-1])
        return 0;
    
    
    for(int i=0; i<len; ++i)
    {
        if(a[0][a_l + i] != a[1][b_l + i])
        {
            ans = 0;
            break;
        }
    }
    
    if(len % 2)
        return ans;
    
    //1. A1-B1, A2-B2
    ans = solve(a_l, (a_l + a_r)/2, )
    
    
    
    //2. A1-B2, A2-B1
    
    
    
    
    
    return 1;
}

int main()
{
    scanf("%s",a[0]);
    scanf("%s",a[1]);
    
    int len = strlen(a[0]);
    
    for(int i=0; i<2; ++i)
    {
        for(int j=1;j<=len;++j)
        {
            if(a[i][j]=='a')
                cnt[i][j]++;
            
            cnt[i][j] += cnt[i][j-1];
        }
    }
    
    solve(1,len,1,len);
    
    
    
    
    
    
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[2][200001];

int solve(int s1, int s2, int len)
{
    int ans = 0;
    
    if(len < 1)
        return 0;
    
    if(!strncmp(str[0]+s1, str[1]+s2, len))
        return 1;
    else
    {
        int s1_half = (s1+len)/2;
        int s2_half = (s2+len)/2;
        
        //int _t[2] = {t, (s+t)/2};
        
        
        //a1-b1 ,, a2-b2
        ans = solve(s1,s2,len/2) & solve(s1_half,s2_half,len/2);
        
        
        //a1-b2 ,, a2-b1
        if(!ans)
            ans = solve(s1, s2_half,len/2) & solve(s1_half, s2,len/2);
        
        
        
        
    }
    return ans;
}

int main()
{
    scanf("%s",str[0]);
    scanf("%s",str[1]);
    
    for(int i=0; i < 5000; ++i)
    {
        str[0][i] = 'a';
        str[1][i] = 'b';
    }
    
    
    if(solve(0,0,strlen(str[0])))
    {
        printf("YES\n");
    }else
        printf("NO\n");
    
    return 0;
}
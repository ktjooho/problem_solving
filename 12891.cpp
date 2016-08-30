#include <cstdio>
#include <cstdlib>

char str[1000001];
int S,P,dna_num[4],dp[1000001],sum[4][1000001];

// 길이, 각 알파벳,  부분 문자열은 연속해서 뽑아야된다.

using namespace std;

int main()
{
    scanf("%d%d",&S,&P);
    str[0]=1;
    scanf("%s",str);
    
    for(int i=0; i<S; ++i)
    {
        
        for(int j=0; j<4 && i; ++j)
            sum[j][i] += sum[j][i-1];
        
        if(str[i]=='A')
            sum[0][i]++;
        else if(str[i]=='C')
            sum[1][i]++;
        else if(str[i]=='G')
            sum[2][i]++;
        else
            sum[3][i]++;
        
    }
    
    for(int i=0; i<4; ++i)
        scanf("%d",&dna_num[i]);
    
    
    for(int i=1; i <= S-P+1; ++i)
    {
        int add = 1;
        
        dp[i] += dp[i-1];
        
        int c[4] = {0,0,0,0};
        
        for(int j=0;j<4;++j)
        {
            int end = sum[j][i+P-2];
            int start;
            
            if(i-2 < 0)
                start = 0;
            else
                start = sum[j][i-2];
            
            c[j] += (dna_num[j]-(end-start));
        }
        
        for(int j=0;j<4; ++j)
        {
            if(c[j]>0)
            {
                add = 0;
                break;
            }
                
        }
        dp[i] += add;
    }
    printf("%d\n",dp[S-P+1]);
    return 0;
}
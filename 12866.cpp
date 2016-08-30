#include <cstdio>
#include <cstdlib>


//D[L][16] = L 까지의 알파벳만 사용해서 만들수있는 state의 경우의 수
// 0,0,0,0 (A,C,G,T 비트의 존재 여부)
/*
    bit_dp 
 
    for(state:0~15)
        d[i+1][state] = d[i][state];
 
 */

int main()
{
    int N;
    char L[1000001];
    unsigned long long result=1;
    
    scanf("%d",&N);
    
    int ACGT[4]={0,};
    getchar();
    for(int i=0; i<N; ++i)
    {
        scanf("%c",&L[i]);
        if(L[i]=='A')
            ACGT[0]++;
        else if(L[i]=='C')
            ACGT[1]++;
        else if(L[i]=='G')
            ACGT[2]++;
        else if(L[i]=='T')
            ACGT[3]++;
    }
    
    for(int i=0; i<4; ++i)
        result = (result * ACGT[i]) % 1000000007;
    
    printf("%llu\n",result);
    
    return 0;
}
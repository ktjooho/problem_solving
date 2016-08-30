#include <cstdio>
#include <cstdlib>

int T,N,i,j,S[100010],d,m[2],t,bEnd,ret[3],cnt;

int main()
{
    scanf("%d",&T);

    while (T--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;++i)
            scanf("%d",&S[i]);

        d = S[2]-S[1];
        cnt=0;
        bEnd=1;
        
        for(i=3; i<=N; ++i)
        {
            signed long long v = (signed long long)d * (S[i]-S[i-1]);
            if(v < 0)
            {
                m[0]=m[1]=S[i];
                t = i-1;
                for(j=i+1; j<=N; ++j)
                {
                    if(S[j]<m[0])
                        m[0] = S[j];
                    if(S[j]>m[1])
                        m[1] = S[j];
                }
                bEnd=0;
                break;
            }
            d = S[i]-S[1];
        }
        for(i=2; i<=t&&!bEnd; ++i)
        {
            if(!(S[i]-S[1]) || (S[i]>S[1] && S[i] < m[0]) || (S[i] < S[1] && S[i] > m[1] ))
                continue;
            for(j=t+1; j<=N; ++j)
            {
                if((S[i]>S[1] && S[i] > S[j]) || (S[i]<S[1] && S[i] < S[j]))
                {
                    ret[0]=1;
                    ret[1]=i;
                    ret[2]=j;
                    cnt=3;
                    bEnd=1;
                    break;
                }
            }
        }
        printf("%d\n",cnt);
        for(i=1;i<=cnt;++i)
            printf(i==cnt?"%d\n":"%d ",ret[i-1]);
    }
    return 0;
}
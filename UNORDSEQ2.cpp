#include <cstdio>
#include <cstdlib>
#include <cstring>

int T,N,i,j,c,m,n,r[3],s[100010],p;
char bEnd,b[1000001][2];

#define E(X) ((X)<0?1:0)
#define A(X) ((X)<0?(-X):(X))

void makeTestCase()
{
    N = 100000;
    for(i=1; i<=N; ++i)
    {
        s[i] = i;
        b[A(s[i])][E(s[i])]=1;
    }
    
}
int main()
{
    scanf("%d",&T);
    //T=1;
    s[0]=0;
    while (T--)
    {
        scanf("%d",&N);
        r[0]=bEnd=c=0;
        p=bEnd=1;
        int kx=0;
        
        for(i=1;i<=N;++i)
        {
            scanf("%d",&s[i]);
            b[A(s[i])][E(s[i])]=1;
            
            /*
            if(i>1)
            {
                if(p>0)
                    p = 1;
                else if(p<0)
                    p = -1;
                if(p * (s[i]-s[i-1]) < 0)
                    bEnd = 0;
                p = s[i]-s[i-1];
            }
            */
        }
        /*
        for(i=2,p=0; i<=N; ++i)
        {
            
            if(p>0)
                p=1;
            else if(p<0)
                p=-1;
            if(p*(s[i]-s[i-1])<0)
            {
                bEnd=0;
                break;
            }
            p=s[i]-s[i-1];
        }
        */
        //makeTestCase();
        bEnd=0;

        for(i=2; i<N&&!bEnd;++i)
        {
            if((s[i]-s[1])&&b[A(s[i])][E(s[i])])
            {
                r[1]=i;
                m=s[i];
                kx++;
                for(j=i+1; j<=N;++j)
                {
                    n=0;
                    if(s[j]-m<0)
                        n=-1;
                    else if(s[j]-m>0)
                        n=1;
                    if(n*(m-s[1])<0)
                    {
                        r[2]=j;
                        r[0]=1;
                        c=3;
                        bEnd=1;
                        break;
                    }
                }
                
                if(kx>1)
                {
                    printf("FUCKER : %d\n",kx);
                   // return 0;
                }
                
               // bEnd=1;
                if(!bEnd)
                    b[A(s[i])][E(s[i])]=0;
            }
        }
        printf("%d\n",c);
        for(i=1;i<=c;++i)
            printf(i==c?"%d\n":"%d ",r[i-1]);
    }
    return 0;
}
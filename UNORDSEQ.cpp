#include <cstdio>
#include <cstdlib>
#include <cstring>

int T,N,s[200001],seq[2],visit[2],i,ret[3],cnt;

int main()
{
  //  scanf("%d",&T);
    T = 1;
    while (T--) {
        scanf("%d",&N);
        
        cnt=ret[0]=seq[0]=seq[1]=0;
        visit[0]=visit[1] = 0;
        
        for(i=0;i<N;++i)
        {
            scanf("%d",&s[i]);
            if(i)
            {
                int d = s[i] - s[i-1];
                
                if(!visit[0]  && (d < 0 || d > 0))
                {
                    if(d<0)
                        seq[0] = -1;
                    else if(d>0)
                        seq[0] = 1;

                    ret[1] = i;
                    visit[0] = 1;
                    if(s[0]==-712825)
                    {
                        printf(">>> I:%d [%d]-[%d] = [%d], seq[%d]\n",i,s[i],s[i-1],d,seq[0]);
                    }

                }
                else if(!visit[1] && (d*seq[0] < 0))
                {
                    if(s[0]==-712825)
                    {
                        printf("I:%d [%d]-[%d] = [%d], seq[%d]\n",i,s[i],s[i-1],d,seq[0]);
                    }
                    visit[1] = 1;
                    ret[2] = i;
                    cnt=3;
                }
            }
        }
        
        printf("%d\n",cnt);
        
        if(s[0]==-712825)
        {
            printf("%d %d %d\n",s[0],s[9923],s[96963]);
            printf("%d %d %d\n",s[79916],s[90009],s[96963]);
//            return 0;
        }
        
        for(i=0;i<cnt;++i)
        {
            if(i<cnt-1)
                printf("%d ",ret[i]+1);
            else
                printf("%d\n",ret[i]+1);
        }        
        
    }
    return 0;
}


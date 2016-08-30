#include <cstdio>
#include <cstdlib>
#include <list>

#define INF 1000000


using namespace std;

// Union_Find


list<int> friendList[2001];
int N,M,A,B,g[2001][2001],ans;

int main()
{
    ans = 1;
    scanf("%d%d",&N,&M);
    memset(g, INF, sizeof(g));
    
    for(int i=0; i<2001; ++i)
        for(int j=0; j<2001;++j)
            g[i][j] = INF;
    
    for(int i=0; i<M;++i)
    {
        scanf("%d%d",&A,&B);
        
        g[A][B] = 1;
        g[B][A] = 1;
        
        // {S1} - A - B
        if(ans){
            for(auto& f : friendList[A])
            {
                printf("F[%d]\n",f);
                if(g[f][B]==INF)
                {
                    g[B][f] = g[f][B] = g[f][A] + g[A][B];
                    friendList[B].push_back(f);
                }
                else
                    
                    if(g[A][f] + g[f][B] != g[A][B])
                        ans = 0;
            }
            
            // {S2} - B - A
            for(auto& f : friendList[B])
            {
                if(g[f][A]==INF)
                {
                    g[A][f] = g[f][A] = g[f][B] + g[B][A];
                    friendList[A].push_back(f);
                }
                else
                    if(g[B][f] + g[f][A] != g[B][A])
                        ans = 0;
            }
            friendList[A].push_back(B);
            friendList[B].push_back(A);
        }
    }
    printf("%d\n",ans);
    return 0;
}

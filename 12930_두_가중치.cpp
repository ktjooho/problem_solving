#include <cstdio>
#include <cstdlib>
#include <vector>

#define INF 100000
#define MAX_SIZE 21
#define DST 1

int w[2][MAX_SIZE][MAX_SIZE],dist[2][MAX_SIZE],visit[2][MAX_SIZE],track[2][MAX_SIZE],n;
vector<int> back[2];
char buf[MAX_SIZE];

using namespace std;

int main()
{
    scanf("%d",&n);
    
    for(int i=0; i<n; ++i)
    {
        for(int k=0; k<2; ++k)
        {
            scanf("%s",buf);
            for(int j=0; j<n;++j)
            {
                if(buf[j]=='.')
                    w[k][i][j] = INF;
                else
                    w[k][i][j] = buf[j]-'0';
            }
        }
    }
    
    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<n; ++j)
            dist[i][j] = INF;
        
        dist[i][0] = 0;
        
        for(int j=0; j<n;++j)
        {
            int u =-1;
            int _min = INF;
            
            for(int k=0; k<n;++k)
            {
                if(dist[i][k]<_min && !visit[i][k]){
                    _min = dist[i][k];
                    u = k;
                }
            }
            if(u==-1) break;
            visit[i][u] = 1;
            
            for(int k=0; k<n; ++k)
            {
                if(k==DST)
                    back[i].push_back(u);
                else if(dist[i][k]>dist )
            }
            
            
        }
        
        
        
    }
    
}
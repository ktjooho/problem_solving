#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;
long long  N,t_shirt;
list<long long > player;
long long t_3;

int main()
{

    scanf("%lld",&N);
    
    for(int i=1; i<=N; ++i)
        player.push_back(i);
    
    list<long long>::iterator iter = player.begin();
    
    for (long long i=1; i<=N; ++i)
    {
        t_3 = ( long long)(i*i*i);
        
        long long offset = (t_3 % ( long long) (N-i+1));
        
        offset = offset - 1;
        
        if(offset < 0)
            offset = N-i;
        
        for(int i=0; i<offset; ++i)
        {
            ++iter;
            if(iter == player.end())
                iter = player.begin();
        }
    
        t_shirt = *iter;
        
        iter = player.erase(iter);
       
        if(iter==player.end())
            iter =player.begin();
    }
    printf("%lld\n",t_shirt);
    
    
    
    return 0;
}


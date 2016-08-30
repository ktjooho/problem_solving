#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int group[3];
int sum;

int cache[1500][1500];

// A + B + C = D
//

int solve(int g0,int g1,int g2)
{
    int ret = 0;
    
    int g[3] = {g0,g1,g2};
    
    for(int i=0; i<2; ++i)
    {
        for(int j=i+1;j<3; ++j)
        {
            if(g[i]<g[j])
            {
                int temp = g[i];
                g[i]=g[j];
                g[j]=temp;
            }
        }
    }
    
    int a=g[0],b=g[1],c=g[2];
    
    if(a==b && b==c)
        return 1;
    
    if(cache[a][b]== (sum - a + b))
    {
        return 0;
    }
    
    else
    {
        cache[a][b] = sum-a+b;
        
        //a,b
        if(a<b)
            ret += solve(a+a, b-a, c);
        else if(a>b)
            ret += solve(a-b, b+b, c);
        
        if(ret)
            return ret;
        //b,c
        if(b<c)
            ret += solve(a, b+b, c-b);
        else if(b>c)
            ret += solve(a, b-c, c+c);
        
        if(ret)
            return ret;
        //a,c
        if(a<c)
            ret += solve(a+a, b, c-a);
        else if(a>c)
            ret += solve(a-c, b, c+c);
        
        if(ret)
            return ret;
    }
    return ret;
}

int main(){
    
    scanf("%d%d%d",&group[0],&group[1],&group[2]);
    
    sum = group[0]+group[1]+group[2];
    
    printf("%d\n",solve(group[0], group[1], group[2]));
    
    
    return 0;
}
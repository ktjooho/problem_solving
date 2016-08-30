#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;
int x,y;
int visit[1000];


int back(int v)
{
    if(v==0)
        return 1;
    
    int av = abs(v);
    int prev=1,next=1;
    
    int k = 0;
    
    while(prev*3<=av)
    {
        prev *= 3;
        k++;
    }
    
    next = prev*3;
   
    
    if(!visit[k+1]){
        visit[k+1] = 1;
        if(back(av-next)){
            return 1;
        }
        visit[k+1] = 0;
    }
    if(!visit[k]){
        visit[k]=1;
        if(back(av-prev)){
            return 1;
        }
        visit[k]=0;
    }
    
    return 0;
}
int main()
{
    scanf("%d%d",&x,&y);
    if(!(back(x)*back(y))){
        printf("0\n");
        return 0;
    }
    int max = -1;
    for(int i=0; i<100;++i)
        if(visit[i])
            max = i;
    for(int i=0; i<=max;++i)
    {
        if(!visit[i])
        {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    
    return 0;
}
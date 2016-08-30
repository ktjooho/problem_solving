#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct Item
{
    int v[3];
    int depth;
};

int main()
{
    int n,result=0;
 
    Item item;
    
    item.v[0] = item.v[1] = item.v[2]=0;
    
    item.depth=0;
    
    scanf("%d",&n);
    
    for(int i=0; i<n; ++i)
        scanf("%d",&item.v[i]);
    
    queue<Item>q;
    
    q.push(item);
    
    while (!q.empty())
    {
        Item v = q.front();
        q.pop();
        
        if((v.v[0]<=0 && v.v[1]<=0) && v.v[2]<=0)
        {
            result = v.depth;
            break;
        }
        else
        {
            Item iv;
            
            iv.depth = v.depth + 1;
            
            iv.v[0] = v.v[0]+1; iv.v[1] = v.v[1]+3; iv.v[2] = v.v[2]+9;
            q.push(iv);
            
            iv.v[0] = v.v[0]+1; iv.v[1] = v.v[1]+9; iv.v[2] = v.v[2]+3;
            q.push(iv);
            
            iv.v[0] = v.v[0]+3; iv.v[1] = v.v[1]+1; iv.v[2] = v.v[2]+9;
            q.push(iv);
            
            iv.v[0] = v.v[0]+3; iv.v[1] = v.v[1]+9; iv.v[2] = v.v[2]+1;
            q.push(iv);

            iv.v[0] = v.v[0]+9; iv.v[1] = v.v[1]+3; iv.v[2] = v.v[2]+1;
            q.push(iv);

            iv.v[0] = v.v[0]+9; iv.v[1] = v.v[1]+1; iv.v[2] = v.v[2]+3;
            q.push(iv);

        }
    }
    printf("%d\n",result);
    return 0;
}
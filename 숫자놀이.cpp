#include <cstdio>
#include <cstdlib>

int main()
{
    int x1,x2,x3,p1,p2,p3;
    
    scanf("%d %d %d %d %d %d",&p1,&p2,&p3,&x1,&x2,&x3);
    
    int limit = p1*p2*p3;
    
    for(int i=x1; i<=limit; ++i){
        
        if((i%p1==x1 && i%p2==x2) && i%p3==x3)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    
    
    
    
    return 0;
}
#include <cstdio>
#include <cstdlib>


int n, brand[51],ans=0,check[51];
int main()
{
    
    
    scanf("%d",&n);
    
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&brand[i]);
        check[brand[i]]++;
    }
    
    for(int i=1; i<=n; ++i)
    {
        int val = 1;
        for(int j=1; j<=i; ++j){
            val *= check[j];
        }
        ans += val;
    }
    printf("%d\n",ans);
    
    
    
    
    
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cmath>


unsigned long long xy[2],sum;
unsigned long long ans;

int main()
{
    scanf("%llu%llu",&xy[0],&xy[1]);
    
    unsigned long long n = (unsigned long long)(floor(sqrt((double)(2*(xy[0]+xy[1])))));
    unsigned long long sum = (n*(n+1))/2;
   // printf("n:%llu\n",n);
    
    if(sum != xy[0]+xy[1])
    {
        printf("-1\n");
        return 0;
    }
    
    while (xy[0]>0)
    {
        ans++;
        if(xy[0] <= n)
        {
            xy[0] = 0;
            break;
        }else{
            
            xy[0] -= n;
            n--;
        
        }
        
    }
    
    printf("%llu\n",ans);
    
    
    // (n+1)*(n) / 2
    
    //
    
    
    
    return 0;
}
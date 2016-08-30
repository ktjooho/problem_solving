#include <algorithm>
#include <cstdio>

using namespace std;

int t,n,is_negative,n_2,max_2,arr[200000],ans;

void process(int i)
{
    if(arr[i]==0)
        n_2=is_negative = 0;
    else
    {
        if(arr[i]<0)
            is_negative = (is_negative + 1)%2;
        if(arr[i]==2 || arr[i]==-2)
            n_2++;
        if(!is_negative)
            max_2 = max(max_2,n_2);
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
       
        max_2 = -1;
        
        n_2=is_negative=0;
        for(int i=0;i<n;++i)
            process(i);
        
        n_2=is_negative=0;
        for(int i=n-1; i>=0;--i)
            process(i);
        
        if(max_2==-1){
            ans = -2;
            for(int i=0; i<n;++i)
                if(ans < arr[i])
                    ans = arr[i];
        }else{
            ans = 1;
            for(int i=0;i<max_2;++i)
                ans = (ans * 2)%1000000007;
        }
        printf("%d\n",ans);
    }
    return 0;
}
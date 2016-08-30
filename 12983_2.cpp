#include <cstdio>
#include <cstdlib>

#define N_LIMIT 10000001
typedef long long LL ;

int nCase,n,pos;
LL data[N_LIMIT],f1,f2;

int main()
{
    pos=f1=f2=0;
    data[0] = 1;
    
    for(int i=1; i<=N_LIMIT;++i){
      
        LL v1 = data[f1]*2+1;
        LL v2 = data[f2]*3+1;
        pos++;
        
        if(v1 < v2){
            f1++;
            data[pos] = v1;
        }else if(v1 > v2){
            f2++;
            data[pos] = v2;
        }else{
            f1++;
            f2++;
            data[pos] = v1;
        }
    }
    int nCase,n;
    scanf("%d",&nCase);
    while (nCase--) {
        scanf("%d",&n);
        printf("%lld\n",data[n-1]);
    }
    
    
    
    return 0;
}
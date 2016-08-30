#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

//1000000000
unsigned long long n,root_n;
vector<int> c;
int main()
{
    for(int i=1; i<=1000; ++i)
    {
        int cnt = 0;
        unsigned long long val = 1;
        for(int j=1; j<=i; ++j)
        {
            if(i%j==0)
                cnt ++;
        }
        for(int k=0; k<cnt; ++k)
            val *= i;
        printf("%d %llu cnt[%d]\n",i,val,cnt);
        
    }
    scanf("%llu",&n);
    
    double f_root_n = sqrt((double)n);
//    printf("%f\n",f_root_n - ceilf(f_root_n));
    if(f_root_n - ceilf(f_root_n) != 0.0){
        printf("-1\n");
        return 0;
    }else{
        root_n = (unsigned long long)f_root_n;
        
        unsigned long long  half_root_n = root_n / 2;
        
        for(int i=1; i<=root_n; ++i)
        {
            int cnt = 0;
            if((root_n%i==0))
            {
                for(int j=1; j<=i; ++j)
                {
                    if((i % j) ==0)
                        cnt++;
                }
                unsigned long long a = 1;
                for(int k=0; k<cnt;++k){
                    a *= i;
                }
                if(a==n){
                    printf("%d\n",i);
                    return 0;
                }
                
                
            }
        
        }
        /*
        for(int i=1; i<=half_root_n; ++i)
        {
            int cnt=0;
            unsigned long long val=1;
            for(int j=1; j<=i; ++j){
                
                if(j > (i/2)){
                    cnt++;
                    break;
                }
                if((i%j)==0) cnt++;
            }
            for(int k=0;k<cnt;++k)
                val *= i;
            if(val == n){
                printf("%llu\n",i);
            }
            
        }
         */
        
    
    }
    
    
    
    
    return 0;
}
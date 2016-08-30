#include <cstdio>

int w,h,a,w_final,h_final,ans;

int getResult(int s, int t)
{
    int result=0;
    while (s>t) {
        int hs;
        
        if(s%2)
            hs = s/2 + 1;
        else
            hs = s/2;
        
        if(hs > t){
            s = hs;
            result++;
        }else{
            s = t;
            result++;
        }
    }
    return result;
}

int main()
{
    ans = 100000000;
    scanf("%d %d %d",&w,&h,&a);
    
    w_final = h_final = -1;
    //종이는 최대 절반
    
    for(int i=1; i<=a; ++i)
    {
        if((a % i==0)){
            
            int x = i;
            int y = a/i;
            
            if(x <= w && y <= h)
            {
                w_final = x;
                h_final = y;
                
                int val = getResult(w, w_final)+getResult(h, h_final);
                
                if(ans > val){
                    ans = val;
                }
                
            }else if(y<=w && x<= h){
                
                w_final = y;
                h_final = x;
                
                int val = getResult(w, w_final)+getResult(h, h_final);
                
                if(ans > val){
                    ans = val;
                }
                
            }
        }
    }
    if(w_final==-1 && h_final==-1)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans);
    
    
    return 0;
}
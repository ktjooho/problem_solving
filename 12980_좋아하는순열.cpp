#include <cstdio>
#include <cstdlib>

int n,s,seq[101],check[101],n_erase,ans;

void solve(int remain)
{
    
    if(remain==0){
      
        int score = 0;
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if(seq[i] < seq[j])
                    score++;
            }
        }
        if(score==s)
        {
            
            ans++;
        }
        return ;
    }else{
        int idx;
        
        for(int i=0; i<n;++i)
        {
            if(!seq[i]){ //비어있는 시퀀스 인덱스 확인
                idx = i;
                break;
            }
        }
        
        for(int i=1; i<=n; ++i)
        {
            if(check[i]==0){ //추가 안된 수 확인
                
                check[i]=1;
                seq[idx] = i;
                solve(remain-1);
                
                check[i]=0;
                seq[idx]=0;
            }
        }
    }
    
}
int main()
{
    scanf("%d %d",&n,&s);
    
    for(int i=0; i<n;++i)
    {
        scanf("%d",&seq[i]);
        check[seq[i]] = 1;
        if(!seq[i]) n_erase++;
    }
    solve(n_erase);
    printf("%d\n",ans);
    
    
    return 0;
}
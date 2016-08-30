#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>


using namespace std;


char s[301];
int m,dp[301][301][301],len,xy[2],cnt;

int main()
{
    
    //sm.insert(make_pair("U", make_pair(0, 1)));
    //sm.insert("U",make_pair(0, 1));
    
    
    scanf("%s",s);
    scanf("%d",&m);
    
    len = strlen(s);
    
    
    for(int i=0; i<len; ++i)
    {
        if((abs(xy[0]) + abs(xy[1])==1) && m > 0)
        {
            int prev_x = xy[0];
            int prev_y = xy[1];
            
            if(s[i]=='U')
            {
                xy[1]++;
            }else if(s[i]=='L'){
                xy[0]--;
            }else if(s[i]=='R'){
                xy[0]++;
            }else{
                xy[1]--;
            }
            
            if(xy[0]!=0 || xy[1] !=0){
                xy[0]=0;
                xy[1]=0;
                m--;
                printf("[%d] 변경 \n",i);
            }
        }else{
            
            if(s[i]=='U')
            {
                xy[1]++;
            }else if(s[i]=='L'){
                xy[0]--;
            }else if(s[i]=='R'){
                xy[0]++;
            }else{
                xy[1]--;
            }

            
        }
        
        
        if(xy[0]==0 && xy[1]==0){
            ++cnt;
        }
        
    }
    printf("%d\n",cnt);
    //연산을 최대 m번 바꿔서 0,0을 방문하는 최대 횟수
    
    //dp[i][j][k] = u-> i+1 l j-1
    //
    
    
    
    
    return 0;
}

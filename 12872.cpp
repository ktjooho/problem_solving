#include <cstdio>
#include <cstdlib>
#include <cstring>


int N,M,P;

long long t[101][101];

long long dp(int pos, int y)
{
    
    //X + Y = N
    if(pos==P)
    {
        if(y==0)
            return 1;
        else
            return 0;
    }
    
    long long &ans = t[pos][y];
    
    if(ans != -1)
        return ans;
    
    ans = 0;
    
    //x+y = N
    
    // N - (y-1)
    
    //아직 리스트에 포함이 안 된 음악을, 뮤직박스에서 하나 꺼냄.
    if(y>0)
        ans += (dp(pos+1, y-1) * (N-y+1))% 1000000007;
    
    if(N-y > M)
        ans += (dp(pos+1, y) * (N-y-M))% 1000000007;
    
    return ans % 1000000007;
}


int main()
{
    memset(t, -1, sizeof(t));
    
    // 플레이 리스트에 노래를 추가함.
    // 길이가 p개인 경우
    // 매우 중요한 조건 - 두 같은 노래에 M개의 노래가 있어야됨.
    // 같은 곡을 들을려면 길이 >= M+2
    // 플레이 리스트에 연속된 일부분을 고른다.
    // 길이 M+1 일부분은 서로 다른 노래만 잇어야됨.
    //
    
    // 노래를 2개의 그룹으로 나눌 수 있음.
    // 들은 노래 // 안 들은 노래
    
    // 3차원 DP로 나누어짐.
    // 이미 들은 노래 , 안 들은 노래
    // 재귀함수
    // D[position][x][y] <- 들은 노래, 안 들은 노래의 갯수
    
    // 안들은 노래를 들을떄 y>0
    // dp -1 로 초기화
    // D[pos+1][x+1][y-1]
    
    
    
    // 들은 노래를 또 들을 경우 x>m
    // D[pos+1][x][y] * (x-m)
    //
    
    scanf("%d%d%d",&N,&M,&P);
    
    //N개의 노래
    //적어도 M개
    //P개의 노래
    printf("%lld\n",dp(0,N));
    
    
    
    return 0;
}
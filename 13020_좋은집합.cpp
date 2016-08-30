#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

long long dp[1<<10][1<<10]; //[수들의 집합][집합안에 있는 수의 최대 길이]
int n;

long long go(int numSet, int len)
{
    //if(numSet  ) //bit count가 1이면
    int bitCnt = bitset<10>(numSet).count();
    
    if(bitCnt==1 || len==1)
        return 1;
    
    long long& ans = dp[numSet][len];
    
    if(ans!=-1) return ans;
    
    ans = 0;
    
    //0x111 , 3
    
    //0x101, 0x110, 0x011 집합
    
    // dp[0x101][2] + dp[0x010][1]
    // dp[0x110][2] + dp[0x001][1]
    
    //do[0x111][3] = dp[0x111][2] + 1
    //
    
    
    
    
    
    
    return ans;
}

int main()
{
    
    memset(dp, -1, sizeof(dp));
    
    scanf("%d",&n);
    
    
    
    
    return 0;
}

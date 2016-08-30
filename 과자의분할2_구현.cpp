#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define INF 10001

int dp[2][5001][2],n,p[10001],t;

/*
    핵심 아이디어 - 분배과정에서 어느 지점에서, 이득이 비용이 발생하나
    인덱스 순회하면서, A에서 B로 바뀌는 순간 비용 발생
     0->1
     1->0
 
 
 */
int main()
{
    cin>>n;
    
    for(int i=1; i<=n-1; ++i)
        cin>>p[i];
    
    for(int i=0; i<2; ++i){
        for(int j=0;j<=n/2; ++j){
            dp[i][j][1]=dp[i][j][0] = INF;
            }
    }
    
    dp[t][0][0] =  dp[t][0][1] = 0;
    
    for(int i=1; i<=n; ++i,t = !t){
        memset(dp+!t, 0x3f, sizeof(dp[!t]));
        for(int j=1; j<=min(i,n/2); ++j){
            dp[!t][j][1] = min(dp[t][j-1][1],dp[t][j-1][0]+p[i-1]);
            dp[!t][j][0] = min(dp[t][j][0], dp[t][j][1]+p[i-1]);
        }
    }
    cout<<min(dp[t][n/2][0],dp[t][n/2][1])<<endl;
    
    
    return 0;
}
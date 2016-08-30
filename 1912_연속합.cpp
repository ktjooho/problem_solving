#include <iostream>
#include <algorithm>

using namespace std;

int  n,arr[100001],dp[100001][2];


int main()
{
    //음수 최소 값
    //양수 최대 값
    //
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    dp[0][1]=dp[0][0]=arr[0];
    
    for(int i=1; i<n; ++i){
        //0은 미포함
        //1은 포함
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = max(dp[i-1][1]+arr[i],arr[i]);
    }
    
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    
    
    return 0;
}
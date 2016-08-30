#include <iostream>

using namespace std;

int dp[10001],n,k,d,c[101];

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; ++i){
        cin>>c[i];
    }
    
    dp[0] = 1;
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<=k; ++j){
            if(j-c[i] >=0)
                dp[j] += dp[j-c[i]];
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}
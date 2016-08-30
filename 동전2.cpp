#include <iostream>
#include <algorithm>

#define MAX_VAL 987654321
using namespace std;
int n,k;
int dp[10001],c[101];

int main(){
    cin>>n>>k;
    
    for(int i=1; i<=k;++i) dp[i] = MAX_VAL;
    for(int i=0; i<n; ++i) cin>>c[i];
    
    for(int i=0;i<n;++i){
        for(int j=1; j<=k; ++j){
            if(j - c[i] >= 0)
                dp[j] = min(dp[j],dp[j-c[i]]+1);
        }
    }
    if(dp[k]==MAX_VAL)
        cout<<-1<<endl;
    else
        cout<<dp[k]<<endl;
    
    
}

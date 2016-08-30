#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#define MAX_NUM 300001
using namespace std;
int n,dp[MAX_NUM],sum;
vector<int>q;

int main()
{
    q.push_back(0);
    q.push_back(1);
    sum = 1;
    
    cin>>n;
    
    for(int i=2;;++i){
        if(sum>=n)
            break;
        sum = q[i-1] + (i*(i+1))/2;
        q.push_back(sum);
    }
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i] = MAX_NUM;
        for(int j=1; j<q.size(); ++j)
            if(i - q[j] >= 0)
                dp[i] = min(dp[i],dp[i-q[j]]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}
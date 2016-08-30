//
//  main.cpp
//  COIIN
//
//  Created by sungjuho on 2014. 8. 24..
//  Copyright (c) 2014년 sungjuho. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

int N,K;
int dp[10001];
int prev[10001];
int input[101];

int solve()
{
    for(int i=0; i < N; ++i)
    {
        for(int j=input[i]; j<=K; j+=input[i])
            dp[j] = dp[j] + 1;
        
        if(i>0)
            for(int k = input[i]; k<=K; ++k)
                for(int j = k-input[i]; j>0; j-=input[i])
                    dp[k] += prev[j];
        memcpy(prev, dp, sizeof(int)*(K+1));
    }
    return dp[K];
}
int main(int argc, const char * argv[])
{
    scanf("%d%d",&N,&K);
    
    for(int i=0; i<N; ++i)
        scanf("%d",&input[i]);

    printf("%d\n",solve());
    return 0;
}


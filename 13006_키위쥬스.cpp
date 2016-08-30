#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

int n,c,cur_cap[16],price[51];

//[쥬스의 양은 안변한다.]
// 쥬스의 양 [49 * 15]
//
//[각 쥬스의 남은 양]
//[A][7]
// 기저조건으로 만들어야 되는데,
// 팔았을때 남은 양
// 팔고 남은 병의 수


//현재 살펴본 병의 번호, 합친 병의 갯수, capacity에 차지않은 용량,
int dp[16][1<<16];
int go(int idx, int set, int cap )
{
    if(idx==4)
    {
        cout<<"IDX"<<idx<<", "<<bitset<16>(set)<<",cap:"<<cap<<endl;
    }
    //printf("idx:%d\n",idx);
    if(idx>n){
        return 0;
    }
    int& ans = dp[idx][set];
    
    /*
    if(ans != -1)
        return ans;
    */
    //ans = 0;
    //추가
    ans = go(idx+1,set,cap)+ price[cur_cap[idx]];
    
    if(cap==c){
      ans =  max(ans,go(idx+1,set|1<<idx,cur_cap[idx]) + price[cur_cap[idx]]);
    }else{
        if(cap + cur_cap[idx] > c){
            
            int d = price[c] + price[cap + cur_cap[idx] - c] - price[cur_cap[idx]] - price[cap];
            ans = max(ans,go(idx+1,set|1<<idx,cap+cur_cap[idx]-c)+d);
            //+ price[C]
            
            //+ price[ cap + cur_cap[idx] - C ]
            
            //- price [ cur_cap[idx] ]
            
            //- price [cap]
            
        }else{ //cap + cur_cap[idx] <= c
            
            // + price[ cap + cur_cap[idx]
            // + price[0]
            // - price [ cap ]
            // - price [ cur_cap[idx] ]
            int d = price[cap+cur_cap[idx]] + price[0] - price[cap] - price[cur_cap[idx]];
            if(d==0)
                d = price[cur_cap[idx]];
            ans = max(ans,go(idx+1,set|1<<idx,cap+cur_cap[idx])+d);
            
        }
    }
    //dp[i][
    
    return ans;
    
}

int main()
{
    for(int i=1<<4; i<(1<<8);i = i + (1<<4)){
        
        cout<<bitset<16>(i)<<endl;
        
    }
    
    memset(dp, -1, sizeof(dp));
    scanf("%d%d",&n,&c);
    for(int i=1; i<=n; ++i){
        scanf("%d",&cur_cap[i]);
    }
    for(int i=0; i<=c;++i)
        scanf("%d",&price[i]);
    
    printf("%d\n",go(1,0,c));
    
    return 0;
}
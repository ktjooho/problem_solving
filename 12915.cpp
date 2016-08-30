#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int v[5],ans;

using namespace std;

//Gready로 접근

//정답을 정하고!

// 2854번

int main()
{
    
    scanf("%d%d%d%d%d",&v[0],&v[1],&v[2],&v[3],&v[4]);
    
    //v[1]과 v[3]의 값을 적절하게 배분해서
    
    // min(v[0],v[2],v[4])의 값이 최대 높은 것으로 뽑아야 된다.
    
    // v[1] -> v[0], v[2]
    
    // v[3] -> v[2], v[4]
    
    // v[i] => min(v0,v2,v4)
    
    // v[1],, v[3]
    int bound = std::max(std::max(v[0],v[4]),v[2]);
    
    // 먼저 동일하게 맞춘다.
    // v[2]가 최소 인 경우
    int d;
    //////////////////////////////////
    d = std::min(bound-v[0],v[1]);
    v[1] -= d;
    v[0] += d;
    //////////////////////////////
    
    d = bound-v[2];
    
    int d_v3_v1 = v[3]-v[1];
    
    if(d_v3_v1 > 0)
    {
        v[2] += std::min(d_v3_v1,d);
        v[3] -= std::min(d_v3_v1,d);
    }else{
        
        d_v3_v1 *= -1;
        v[2] += std::min(d_v3_v1,d);
        v[1] -= std::min(d_v3_v1,d);
    }
    
    d -= d_v3_v1;
    
    if(d > 0) //나눠서 분납
    {
        int half_v1 = d / 2;
        int half_v3 = d / 2;
        
        if(d%2)
            half_v3++;
        
        v[2] += std::min(half_v1,v[1]);
        v[1] -= std::min(half_v1,v[1]);
        
        v[2] += std::min(half_v3, v[3]);
        v[3] -= std::min(half_v3, v[3]);
    }
    
    d = std::min(bound-v[4],v[3]);
    v[3] -= d;
    v[4] += d;
    
    int mean = (v[1] + v[3])/3;
    
    d = std::min(std::min(mean,v[1]),v[3]);
    
    v[0] += d;
    v[2] += d;
    v[4] += d;
    
    ans = std::min(std::min(v[0],v[2]),v[4]);
    
    printf("%d\n",ans);
    
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
short dp[10001][5000],c[2],p[10001];

//N개는
// (N-2)개의 총 경우의 수에



/*
 
  서로 중복되지않는 조합이 있다. 근데 그 조합의 갯수가 N^2미만이면 이 문제를 풀 수 있다. => 방법1)
   => 처음 A와 B의 크기의 합읍  N/2 보다 커야된다는 가정이 틀렸다.
   => A+B = K가 두 번 체크가 되었기때문에.. 한번 선택에서 K를 골랐을때.. 당연히 그게 더 최소값을 보장하는 줄 알았지만.
   => 두 번 선택에서 k를 골랐을때
 
 
  특정 위치 i에서의 선택은 N-I가 됨.

  끝나는 위치 : N/2, N/2 + 1, ...  ~ N-2에서 끝이난다.
 
  1/3/2
 
  이전에 선택할 수 있는 갯 수 : 0개,1개,    N/2 - 1 개
 
 아닐 경우, 특정 조건을 만족하는 점화식을 세워야 한다. => 방법2)
 
 방법2로는 시간초과가 걸렸다. 뭔가 포함관계를 이용해서 풀 수 있을 것 같기도함.
 
 
 배열 사이즈 최대 크기와 힘의 최대크기가 같다. 뭔가 이점을 이용해야된다.
 
 그리고 마지막으로 자르는 위치에 따라서, 나올 수 있는 경우의 수가 달라 진다.
 
 n/2는 한개밖에 안 나온다. 최소값은 절반이랑 같거나, 작을 수 있다.
 
 
 N/2 <= i <= N-1 에서 자르는 경우.
 
 i번째를 마지막으로 자르는 경우에는 바로 이전 단계 자르는 겨
 
 ------------------------------------------
 A1 B1 A2 B2 .... Ak Bk
 
 A1 + A2 + ... AK or Ak-1 = N/2
 
 B1 + B2 + ... BK or Bk-1 = N/2
 
 A와 B의 갯수 차이는 많아봤자 1이다. 
 
 A와 B가 번갈아가면서 채워넣음.
 
 
 
 
 
 -> Greedy 방식으로 푸는 법.

 -> 0부터 p[n/2]까지 정한 다음에 값을 풀어나가면 될 것 같다.
 
 ->
 
 
 
 
 
 A1 + B1 => N/2일 경우, A1 = N/2,
 
  A[N-2]로 끝나는 경우의 최대값.
  
 A[N-2] = A[N-3][1] OR A[N-4][2] ... A[N/2 - 2]
 
  A[N-3]으로 끝나는 경우의 최대값.
     .
     .
     .
     .
  A[N/2]로 끝나는 경우의 최대값.
 
   
 
 
 

 
 
 A1 : 1 ~ N/2 => (N/2)
 B1 : 1 ~ N/2 =>
 A2 : (N/2 - 1) ~ 0 (N/2 - 1)
 A3 :
 
 F(2) = 1 / 1
 F(4) = 1 /2/ 1 OR 2 / 2
 F(6) = (1/3/2), (2/1/3), (3/3), (1/1/2/2)
 F(8) = (1/4/3),(2/3/2/1),(3/4/1),(4/4)
 F(10) = (3/3/1/2/1)
 F(N) = (1,.. ) (2,... ) , (3,...) ... (N/2, N/2).. (3, N -2, N - 3,2)
 
 
 */
int g;
void makeTest()
{
    srand((unsigned int) time(NULL));
    n = 10000;
    for(int i=1; i<=n-1; ++i){
        p[i] = rand() % 10001;
    }
}
short go(int turn, int remain, int pos)
{
    
    if(pos <= 0)
        return 0;
    
    short& ans = dp[pos][remain];
    
    if(ans!= -1)
    {
//        g++;
        return ans;
    }
    g++;
    ans = 0;
    
    int limit = pos - remain;
    
    if(remain == 0 || limit == 0)
        return ans = p[pos];
    
    if(turn)
    {
        for(int i=1; i<=remain; ++i)
        {
            short  v = min(go(turn^1, remain-i, pos -i)+p[pos],10000);
            
            if(ans == 0)
                ans = v;
            else
                ans = min(ans,v);
        }
    }
    else
    {
        for(int i=1; i<=limit; ++i){
            
            short  v = min(go(turn^1, remain, pos -i)+p[pos],10000);
            
            if(ans == 0)
                ans = v;
            else
                ans = min(ans, v);
        }
    }
    return ans;
}

int main()
{
    short min = 10000;
    cin>>n;
    for(int i=1; i<=n-1; ++i)
        cin>>p[i];
    
    makeTest();
    memset(dp, -1, sizeof(dp));
    
    //위치 I에서, A의 양
    //  1 or 0(I <= A <= Min(I, n/2)
    
    // I <= N/2 일 경우
    // 0 <= A <= I
    
    // I > N/2 일 경우
    // 1 <= A <= N - I
    
    
    // D[I][K] = I번째까지 과자를 분배하고 A가 K개 만큼 가졌을 경우, 소요되는 힘의 최소값.
    // D[N][N/2] =>  FIND MIN ( D[N-1][N/2 - 1], ... D[N-K][N/2 - K] ... D[N/2][0] )
    // D[I][K] = D[I-1][K-1], D[I-2][K-2] .... D[I-L][K-L] <- 배열 순회를 한번 더 해야하므로, N^3임.
    // 위에선 불필요하게, 뭔가 중복이 되는 경우가 많다. 가령 포함관계같은.
    
    // 놓친 내꺼를 가져가다가, 다른 사람꺼를 줘버리면.. 그때 값이 올라간다.
    //
    
    // 핵심은 AAA로 가다가 바뀌는 순간, P를 포함시킨다.
    //
    
    // (포함 , 비포함)에 대해 생각은 했는데, 이거를 식으로 나타내지를 못했다.
    
    
    // 소유자가 바뀌는 경우에 따라, 비용(우리가 연산에서 고려하고자 하는)이 발생.
    // D[I][J][0] = MIN ( D[I-1][J][1] + P[i] , D[I-1][J][0])
    // D[I][J][1] = MIN ( D[I-1][J-1][1], D[I-1][J-1][0] + XX )
    
    
    // 위 방식은 N^3이다.
    // 문제를 좀 다른 방식으로 봐야된다.
    
    // N^2으로 푸는 방법.....
    // 아니면 N혹은 NlogN으로 푸는 방법.
    //
    // 정렬을 해서 접근.
    //

    
    //D[I-1][K-1], D[I-1][K], I-1에서 K-1에서 하나를 더 추가, I-1에서 K에서 B쪽에 하나를 추가.
    //자르는 부분이 달라지나.
    
    
    for(int i=1; i<=n-1; ++i){
        if(i <= n/2){
            for(int j=0; j<=i; ++j){
//                dp[i]
                //index i까지 진행했을때, a가 얼만큼 채워졌을때 최소값.
                //i-1을 보았을때.
                //
            }
        }else{
            for(int j=1; j<= n-i; ++j){
                
                
            }
        }
    }
    
    for(int i=n/2; i<=n-1; ++i)
    {
        short v = go(0,i - n/2, i);
//        cout<<"G:"<<g<<endl;
        if(min > v)
        {
//            cout<<"I:"<<i<<endl;
            min = v;
        }
    }
    cout<<min<<endl;
    
    return 0;
}
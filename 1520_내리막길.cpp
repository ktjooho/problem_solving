#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n,m,b[501][501],dp[501][501];
const int v[4][2] = { {-1,0},{1,0},{0,1},{0,-1}};

int go(int i, int j){
    
    if(i<=0 && j<=0)
        return 1;
    
    int& ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    
    for(int p=0;p<4;++p){
        int dx = v[p][0]+i, dy = v[p][1]+j;
        if(dx< 0|| dx>m)
            continue;
        if(dy<0||dy>n)
            continue;
        if(b[dx][dy] > b[i][j])
            ans += go(dx,dy);
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>m>>n;
    for(int i=0; i<m; ++i)
        for(int j=0;j<n;++j)
            cin>>b[i][j];
    cout<<go(m-1,n-1)<<endl;
    return 0;
}
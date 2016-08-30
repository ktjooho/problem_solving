#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> vec;
vector<int> yaksu;

int cnt[2001][1000];
int ym[1000001];
int n,k;
LL ans;

int gcd(LL a, LL b)
{
    while (b != 0)
    {
        LL temp = a % b;
        a = b;
        b = temp;
    }
    return abs((int)a);
}
int main()
{
    cin>>n>>k;
    
    for(int i=1; i<=k; ++i)
        if(k%i == 0)
            yaksu.push_back(i);
    for(int i=0; i<yaksu.size(); ++i)
        ym[yaksu[i]] = i;
    
    vec.resize(n);
    
    for(int i=0; i<n;++i)
    {
        cin>>vec[i];
        for(int j=0; j<yaksu.size(); ++j){
            if(i>0)
                cnt[i][j] += cnt[i-1][j];
            if(vec[i]%yaksu[j] == 0)
                cnt[i][j]++;
        }
    }
    for(int p=0; p<=n-3; ++p){
        for(int q=p+1; q<=n-2; ++q){
            LL pq = vec[p]*vec[q];
            int  g = gcd(pq, k);
            int yk = k / g;
            ans += cnt[n-1][ym[yk]] - cnt[q][ym[yk]];
        }
    }
    cout<<ans<<endl;
    return 0;
}
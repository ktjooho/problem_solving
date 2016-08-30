#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int t,n[2],d;
typedef long long LL;

int getSum(vector<int>&v, int val)
{
    int sum = 0;
    for(auto d : v)
        sum += abs(d-val);
    return sum;
}
int main()
{
    cin>>t;
    while (t--) {
        vector<int> v[2];
        int s,e;
        cin>>n[0]>>n[1];
        for(int i=0; i<2; ++i){
            for(int j=0; j<n[i];++j){
                cin>>d;
                v[i].push_back(d);
            }
            sort(v[i].begin(),v[i].end());
        }
        s = min(v[0].front(),v[1].front());
        e = max(v[0].back(),v[1].back());
        
        double ans;
        LL dist = 0,min;
        LL sum[2] = {getSum(v[0], s),getSum(v[1], s)};
        
        min = dist = sum[0]*n[1] + sum[1]*n[0];
        ans = s;
        
        int p[2]={0,0};
        
        for(int i=0;i<2;++i)
            if(s==v[i][0])
                p[i]++;
        
        for(int i=s+1; i<=e; ++i){
            for(int j=0; j<2; ++j){
                sum[j] = sum[j] - (n[j] - 2*p[j]);
                if(i ==v[j][p[j]])
                    p[j]++;
            }
            dist = sum[0]*n[1] + sum[1]*n[0];
            if(min > dist){
                min = dist;
                ans = i;
            }else
                break;
        }
        printf("%.1f\n",ans);
   }
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int n;
double w[51],c[51];
vector<double> dn;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        scanf("%lf",&c[i]);
    for(int i=0; i<n; ++i)
        scanf("%lf",&w[i]);
    
    for(int i=0; i<n; ++i)
        dn.push_back((w[i]/c[i]));
    
    sort(dn.begin(),dn.end());
   
    double min = 500000000.0f;
    
    double sum = 0.0f;
    
    for(auto&d : dn){
        sum = 0.0f;
        for(int j=0; j<n; ++j)
        {
            sum += abs((c[j]*d) - w[j]);
        }
        if(sum < min)
            min = sum;
    }
    printf("%.9lf\n",min);
    
    
    
    
    return 0;
}
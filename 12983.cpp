#include <cstdio>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

#define N_LIMIT 10000000

using namespace std;

priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long>> calc;

int nCase,n;

vector<unsigned long long> v(N_LIMIT+1);


int main()
{
    int cnt=0;
    calc.push(1);
    
    while(!calc.empty()&& cnt<N_LIMIT)
    {
        unsigned long long t = calc.top();calc.pop();
        
        while(!calc.empty() && t==calc.top()){
            calc.pop();
        }
        v[cnt++] = t;
        
        unsigned long long f1 = 2*t+1;
        unsigned long long f2 = 3*t+1;
        calc.push(f1);
        calc.push(f2);
    }
    cin>>nCase;
    
    while (nCase--)
    {
        cin>>n;
        cout<<v[n-1]<<endl;
    }
    
    
    return 0;
}
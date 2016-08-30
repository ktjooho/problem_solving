#include <iostream>
#include <algorithm>

int n[1000001],x;

using namespace std;

int main()
{
    cin>>x;
    for(int i=2; i<=x;++i)
        n[i] = 2000000;
    
    for(int i=2;i<=x;++i){
        
        n[i] = min(n[i],n[i-1] + 1);
        
        for(int k=2;k<=3;++k)
            if(i%k==0)
                n[i] = min(n[i],n[i/k]+1);
        
    }
    cout<<n[x]<<endl;
    
    return 0;
}
#include <iostream>

int n,k,c[11],ans;

using namespace std;

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i)
        cin>>c[i];
    for(int i=n; i>0 && k; i--){
        ans += (k/c[i]);
        k -= (k/c[i]) * c[i];
    }
    cout<<ans<<endl;
    return 0;
}
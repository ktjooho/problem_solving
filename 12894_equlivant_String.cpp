#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
string a,b;

void go(string& str, int start, int end)
{
    if((end-start + 1)%2)
        return ;
    
    int half = (start + end)/2;
    
    go(str,start,half); go(str,half+1,end);
    
    if(str.compare(start,half-start+1,str.substr(half+1,end-half)) > 0)
        swap_ranges(str.begin()+start, str.begin()+half+1, str.begin()+half+1);
    
    return ;
}

int main()
{
    cin>>a>>b;
    
    go(a,0,a.length()-1);
    go(b,0,b.length()-1);
    
    if(a.compare(b)!=0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    
    return 0;
}
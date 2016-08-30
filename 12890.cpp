#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned long long n;
int d1,d2,c1,c2,l;
string str,ns;
vector<string> cache[20][20];

void make(int c1, int c2,int n1, int n2, string s)
{
    if(c1<=0 && c2<=0)
    {
        cache[n1][n2].push_back(s);
        return ;
    }
    if(c1){
        s.push_back(d1+'0');
        make(c1-1, c2,n1,n2, s);
        s.pop_back();
    }
    if(c2){
        s.push_back(d2+'0');
        make(c1,c2-1,n1,n2,s);
        s.pop_back();
    }
    return ;
}
void makeCache()
{
    
    for(int i=0; i<=c1; ++i){
        for(int j=0; j<=c2;++j)
        {
            str = "";
            make(i, j, i , j , str);
            sort(cache[i][j].begin(),cache[i][j].end());
        }
    }
}
int makeResult(string s, int pos)
{
    if(count(s.begin(), s.end(), d1+'0')>=c1 && count(s.begin(), s.end(), d2+'0')>=c2)
    {
        cout<<s<<endl;
        return 1;
    }
    
    int _c1=0,_c2=0;
    int len = s.length() - pos + 1;
    
    _c1 = count(s.begin(), s.end()-len, d1+'0');
    _c2 = count(s.begin(), s.end()-len,d2+'0');
    
    _c1 = max(0,c1-_c1);
    _c2 = max(0,c2-_c2);
    
    if(_c1 + _c2 > len)
        return makeResult(s, pos-1);
    
    vector<string>& vs = cache[_c1][_c2];
    
    string ms = vs[vs.size()-1];
    
    
    if(ms.compare(0,len ,s.substr(pos-1, len)) < 0)
    {
        unsigned long long v = 0;
        
        for(int i=0; i< s.length() - len; ++i)
            v = v*10 + (s[i]-'0');
        v++;
        
        for(int i=0; i<len; ++i)
            v*=10;
        
        s = to_string(v);
        
        return makeResult(s, s.length());
        
    }else{
        
        for(auto& ms : vs){
            if(ms.compare(0,len,s.substr(pos-1,len))>0){
                s.replace(pos-1, len, ms);
                return makeResult(s, pos-1);
            }
        }
    }
    
    return 0;
}
int main()
{
    cin>>n>>d1>>c1>>d2>>c2;
    
    if(d1>d2)
    {
        swap(d1, d2);
        swap(c1,c2);
    }
    
    ns = to_string(n);
    
    if(ns.length() < c1 + c2){
        if(d1==0)
        {
            str.push_back(d2 +'0');
            c2--;
        }
        for(int i=0; i<c1;++i)
            str.push_back(d1+'0');
        for(int i=0; i<c2; ++i)
            str.push_back(d2+'0');
        cout<<str<<endl;
    }else{
        makeCache();
        makeResult(ns, ns.length());
    }
    return 0;
}
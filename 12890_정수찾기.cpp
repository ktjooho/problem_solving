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
int g;

/*
 
 114501 0 4 2 3
 
 47 1 0 2 0
 
 47 5 0 9 1
 
 225 2 1 3 1 - 230
 
 s1->(axxx)(2000022)<-s2
 
 . s1 is set of diff in length between l ( N - (c1+c2) >= 0 )
 . if s1 part has elements of d1 or d2
 . then
 .
 . if l < 0, then it's easy to get answer.
 .
 
 .3000 // 2000022
 
 .3220 // 7000000
 
 .3220 // 7000002
 
 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
 (axxx + 1) ( )
 
 
 322099929920 2 4 0 4
 322100000022
 */

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
            /*
            for(auto& s : cache[i][j]){
                cout<<"i:"<<i<<",j:"<<j<<","<<s<<endl;
            }
             */
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
    
    
//    cout<<"ms:"<<ms<<endl;
//    cout<<"비교 문자열:"<<s.substr(pos-1,len)<<endl;
    
    if(ms.compare(0,len ,s.substr(pos-1, len)) < 0)
    {
        /*
        if(g){
            while (1) {
                ;
            }
        }
        g++;
        */
        unsigned long long v = 0;
        
        for(int i=0; i< s.length() - len; ++i)
            v = v*10 + (s[i]-'0');
        v++;
        
        for(int i=0; i<len; ++i)
            v*=10;
        
        s = to_string(v);
        
//        cout<<"changed s:"<<s<<endl;
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
//100000 0 10 5 4
//299378099901829 4 7 1 6
//599666669901829 6 7 8 5
//358358392384383 9 4 4 9
//984845884477272 7 6 0 1
//68909557 5 6 0 1
//29392 4 2 0 2
//58345797373848 0 7 9 8
//322099929920 2 3 0 4
// 7676768997 5 3 2 1
// 50 6 1 0 1
// 610190
// 8995 9 2 0 1
//22222222222 1 5 0 5
// 212148232939 4 8 3 2
// 1200001000000 0 10 9 3
// 11341232323222 0 10 9 3
// 32918121413284 4 8 8 4
// 34828192838377 5 7 8 4
// 234723461263621 9 5 6 7
// 899237722831223 9 5 2 8
int main()
{
    cin>>n>>d1>>c1>>d2>>c2;
    
    if(d1>d2)
    {
        swap(d1, d2);
        swap(c1,c2);
    }
    
    ns = to_string(n);
    //cout<<ns.length()<<endl;
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
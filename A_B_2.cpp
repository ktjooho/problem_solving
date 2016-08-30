#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


string s,t;
map<string,int> cache;

int dfs(string str)
{
    //cout<<"STR:"<<str<<endl;
    
    if(str.length()==s.length())
    {
        if(str.compare(s)==0)
            return 1;
        else
            return 0;
    }
    char last_ch = str[str.length()-1];
    char first_ch = str[0];
    
    if(last_ch=='A')
    {
        if(first_ch=='B')
        {
            string temp = str;
            str = str.substr(1,str.length());
            std::reverse(str.begin(), str.end());
            
            int ans = dfs(str);
            if(ans)
                return ans;
            
            
            str = temp;
            str.pop_back();
            return dfs(str);
            
        }
        else
            str.pop_back();
    }
    
    else if(last_ch==first_ch)
    {
        str =str.substr(1,str.length());
        std::reverse(str.begin(), str.end());
        
    }else{
        return 0;
    }

    return dfs(str);
}

int main()
{
    //첫 시작과 끝이 B이면 조건2번 적용.
    //첫 시작이 A이고 끝이 B면은 검사 안함.
    
    // BXXB
    
    // A XX A 끝이 A이면 얼마든지 가능
    // B XX A

    cin>>s>>t;
    cout<<dfs(t)<<endl;
    return 0;
}
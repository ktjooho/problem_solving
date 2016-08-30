#include <iostream>
#include <string>
using namespace std;

string a,b;
char c[26];

int main()
{
    cin>>a>>b;
    for(int i=0; i<a.length(); ++i)
    {
        c[a[i]-'A']++;
        c[b[i]-'A']--;
    }
    for(int i=0; i<26;++i){
        if(c[i]!=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    //옮기는 횟수 :i개 고정된 갯수 : N-i개
    for(int i=0; i<a.length(); ++i)
    {
        int startPos = i;
        
        for(int j=0; j<a.length(); ++j)
            if(a[j] == b[startPos])
                startPos++;
        
        if(startPos == b.length())
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
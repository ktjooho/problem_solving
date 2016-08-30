#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;

#define MOD 1000000007

string str;

LL table[500][500];

/*
    부분 문자열 정의 : 일부 문자열을 지운다.
 
    i에서 j까지 올바른 부분 문자열
 
    
    부분 문자열이 되는 구간을 확인할 수 있다.
 

    여기서부터, 부분 문자열을 조립을 해야된다. 
 
    i부터 j까지, 길이가 k가 되는
 
 ()()()()
 
 
     (())()
 
    
   ()()
   (())
   () 
 
  
 
 
    C =  (A) => A
    
    C =  (A) (B) => (AB)
      
    I - J =
    " "
    (()()())
    ()()()()()()()()
    ()(())()
    (())()()
     ( ()()() )
     ( () )
 
     ()()()
 
     ()()
     (())
 
 
     ()()
     (())
 
   (()())
   ((()))  f(4) +
 
  ()()()  2 * f(2) * f(4)
  ()(())
  (())()
 
 
  
  f(n) = f(n-2) + (k < n-2) ..
 */

LL go(int last, int open)
{
    LL& ans = table[last][open];
    
    if(ans != -1) return ans;
    
    ans = 0;
    
    if(open==0)
        ans = 1;
    
    int n = str.length();
    int next_open=last+1;
    int next_close=last+1;
    
    while(next_open < n && str[next_open]!='('){
        next_open++;
    }
    if(next_open < n)
        ans += go(next_open, open+1);
    
    if(open>0){
        while (next_close<n && str[next_close]!=')') {
            next_close++;
        }
        if(next_close < n)
            ans += go(next_close,open-1);
    }
    ans %= MOD;
    return ans;
}
int main()
{
    cin>>str;
    // i to j
    memset(table, -1, sizeof(table));
    
    str = ' '+str;
    cout<<go(0,0)-1<<endl;
    return 0;
}
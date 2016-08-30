#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define T_SIZE 900
deque<int>q;
string a,t,ans;
int a_len,t_len,d,front,back,link[2][T_SIZE];
bool b[T_SIZE];
/*
 
 1.양방향 연결리스트 구현하는 방법.
 2.while(
 
 
 */


// xxxxx a(aaab)aab
// xxxxxaa(aaab)ab
// xxxxxaaa(aaab)b

// s1s2
// s1s1s1s1s1s2s2s2s2

// aaaabbbb
//aa[aabb]bbaa[aabb]bb
//
//aabb
//ab
//aabb
//aaaaaaab[aabb]bbbbbb
// aa aabb bb
// 12 1234 34

// atataa aabb bbfbfb
// 1212 1234 3434
// abc
// xzcvxzcvzxvc[a(abc)bc]qwewqdwqd

//a
//aba
//ababa
//aba
//aabbaabbaa
//
//1 s n-1
//[aaaabbbb]

//(f-(n-1),0), (0,f-1)
// a[i] = t[n]
// n = link[n]
// 일치한다면, push
//


//aa (aabb(aa)bbaa) aabbaa
//aaaa(aa(aabb)bb)bbbb
int main()
{
    cin>>a>>t;
    a_len = a.length();
    t_len = t.length();
    
    for(int i=0; i<t_len-1;++i)
    {
        link[0][i] = i+1;
        link[1][t_len-1-i] = t_len-2-i;
    }
    
    link[t_len-1] = -1;
    
    for(int i=0; i<t_len;++i)
        if(!t.compare(i, a_len, a))
            q.push_back(i);
    
    for(int i=1; !q.empty(); i^=1)
    {
        if(i%2)
        {
            front = q.front();
            q.pop_front();
            
            bool br = false;
            for(int j=0,n=front;j<a_len;++j,n=link[n]){
                if(b[n]){
                    br=true;
                    break;
                }
            }
            //ababaabb
            if(br)
            {
                continue;
            }
            cout<<"front:"<<front<<endl;
            for(int j=0,n=front;j<a_len;++j,n=link[0][n])
                b[n] = 1;
            
            if(front){
                int n = front;
                for(int j=0; j<a_len;++j)
                    n = link[0][n];
                link[0][front-1] = n;
                link[1][n] = front -1;
            }
            
            for(int j=max(0,front-a_len+1);j<=front-1;++j){
                bool bEqual = true;
                for(int k=0,n=j; k<a_len;++k,n=link[n]){
                    if(b[n]){
                        bEqual=false;
                        break;
                    }
                    if(t[n]!=a[k]){
                        bEqual = false;
                        break;
                    }
                }
                if(bEqual)
                    q.push_front(j);
            }
        }
        else
        {
            back = q.back();
            q.pop_back();
            
            bool br = false;
            for(int j=0,n=back;j<a_len;++j,n=link[n]){
                if(b[n]){
                    br=true;
                    break;
                }
            }
            if(br)
            {
                continue;
            }

            cout<<"back:"<<back<<endl;
            for(int j=0,n=back;j<a_len;++j,n=link[n])
                b[n]=1;
            if(back)
            {
                int n = back;
                for(int j=0; j<a_len;++j)
                    n = link[n];
                link[back-1] = n;
                if(b[back-1] || b[link[back-1]]){
                    ;
                }
            }
            for(int j=max(0,back-a_len+1);j<=back-1;++j){
                bool bEqual = true;
                for(int k=0,n=j; k<a_len;++k,n=link[n]){
                    if(b[n]){
                        bEqual=false;
                        break;
                    }
                    if(t[n]!=a[k]){
                        bEqual = false;
                        break;
                    }
                }
                if(bEqual)
                    q.push_back(j);
            }
        }
    }
    
    /*
    for(int i=0; i<t_len; ++i)
        if(!b[i])cout<<t[i];
    cout<<endl;
     
     ab
     a(ab)a(ab)bbaa(ab)qbaq
     aa(ab)bbaa(ab)qbaq
     aa(ab)bbaaqbaq
     a(ab)baaqbaq
     (ab)aaqabq
     
    */
    
    for(int i=0; i<t.length();++i)
        if(!b[i]) ans.push_back(t[i]);
    
    
    set<int> err;
    
    for(int i=0;i<ans.length();++i)
    {
        if(!ans.compare(i,a_len,a))
        {
            err.insert(i);
            //cout<<"Catch Error Idx:"<<i<<endl;
        }
    }
    for(int i=0; i<ans.length();++i)
    {
        cout<<ans[i];
        if(err.find(i)!=err.end())
                cout<<"["<<i<<"]";
    }
        
    cout<<endl;
    cout<<t_len<<","<<ans.length()<<endl;
    
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;
#define T_SIZE 350000

string s;
deque<int>q;
char a[30],t[T_SIZE];
int l[2][T_SIZE],t_len,a_len,front,back;
bool v[T_SIZE];

int check_visit(int p)
{
    for(int i=1;i<=a_len;++i,p=l[0][p])
    {
        if(p==-1){while(1){;}}
        if(v[p] || (a[i]!=t[p]))
            return 1;
    }
    return 0;
}
int visit(int p)
{
    for(int i=1;i<=a_len;p=l[0][p],++i)
        v[p]=1;
    return p;
}
int check_match(int p)
{
    for(int i=1;i<=a_len;++i,p=l[0][p])
    {
        if(p==-1)return 0;
        if(t[p]!=a[i])return 0;
    }
    return 1;
}
int link(int prev, int next)
{
    if(prev==-1||next==-1)return 0;
    if(v[prev]||v[next])return 0;
    l[0][prev]=next;
    l[1][next]=prev;
    return 1;
}
int main()
{
    scanf("%s%s",a+1,t+1);
    t_len = strlen(t+1), a_len = strlen(a+1);
    
    for(int i=1; i<t_len; ++i)
    {
        l[0][i] = i+1;
        l[1][t_len-i+1] = t_len - i;
    }
    
    l[1][1]=l[0][t_len]=-1;
    
    for(int i=1;i<=t_len;++i)
        if(!strncmp(t+i, a+1, a_len))
            q.push_back(i);
    
    for(int s=1;!q.empty();s^=1)
    {
        if(s%2)
        {
            front = q.front();
            q.pop_front();
            if(check_visit(front)){
                s^=1;
                continue;
            }
            int next = visit(front);
            int prev = l[1][front];
            
            if(link(prev, next)){
                for(int i=0; i<a_len-1 && prev != -1; ++i,prev=l[1][prev]){
                    if(check_match(prev))
                        q.push_front(prev);
                }
            }
        }
        //xxa(aab)xxxxxaa(aab)xxa(aab)a(aab)a(aab)(aab)a(aab)xx
        else
        {
            back = q.back();
            
            q.pop_back();
            
            if(check_visit(back)){
                s^=1;
                continue;
            }
            int next = visit(back);
            int prev = l[1][back];
            if(link(prev, next))
            {
                for(int i=0; i<a_len-1 && prev != -1; ++i,prev=l[1][prev])
                {
                    if(check_match(prev))
                        q.push_back(prev);
                }
            }
        }
        if(front > t_len || back > t_len) {while(1){;}}
    }
    for(int i=1; i<=t_len; ++i){
        if(!v[i]){
            printf("%c",t[i]);
        }
    }
    printf("\n");
    return 0;
}
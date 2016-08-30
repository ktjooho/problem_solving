#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <stdexcept>

using namespace std;

int n[3];

vector<string> str(3);
vector<string> abc(3);

set<tuple<string,string,string,int>> s;
//queue<tuple<string,string,string,int>> q;

queue<vector<string>> q;
map<vector<string>,int> m;


int main(){
    
    for(int i=0; i<3; ++i)
    {
        cin>>n[i];
        if(n[i])
        {
            cin>>str[i];
            for(auto s: str[i])
                abc[s-'A'].push_back(s);
        }
    }
    
    auto node = make_tuple(str[0],str[1],str[2],0);
    
    q.push(str);
    m[str]=0;
    
    int ans =0;
    
    while(!q.empty()){
        
        auto current = q.front();
        q.pop();
        
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                
                if(i==j) continue;
                
                if(current[i].length()==0) continue;
                
                vector<string>next(current);
                
                auto c = next[i].back();
                next[j].push_back(c);
                next[i].pop_back();
                
                if(m.count(next)==0){
                    m[next] = m[current] + 1;
                    q.push(next);
                }
            }
            
        }
        
    }
    cout<<m[abc]<<endl;
    
    
    //dfs(0,0,0);
    
    return 0;
}
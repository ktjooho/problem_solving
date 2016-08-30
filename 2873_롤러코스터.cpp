#include <iostream>
#include <string>
#include <cstring>
#include <map>


using namespace std;

typedef pair<int, int> PII;
#define LEN 1001
int r,c,b[LEN][LEN],v[LEN][LEN];
string str;

void search_path()
{
    v[1][1] = 1;
    int i=1, j=1;
    
    map<string,PII> m;
    
    m["R"].first = 0, m["R"].second = 1, m["L"].first = 0, m["L"].second = -1;
    m["U"].first = -1, m["U"].second = 0, m["D"].first = 1, m["D"].second = 0;
    
    map<string,int> t;
    t["U"]=0; t["R"]=1; t["L"]=2; t["D"]=3;
    
    while (i<r || j<c) {
        if(i >= r-1){
            t["U"]=0,t["L"]=1,t["D"]=2,t["R"]=3;
        }
        
        int min=4;
        string command;

        for(auto e:m){
            if(!v[i+e.second.first][j+e.second.second]){
                if(t[e.first]<min){
                    min = t[e.first];
                    command = e.first;
                }
            }
        }
        if(j==c)
            t["L"]=1,t["R"]=2;
        else if(j==1)
            t["L"]=2,t["R"]=1;
        
        i += m[command].first, j += m[command].second;
        
        v[i][j] = 1;
        
        cout<<command;
    }
    
}
void solve()
{
    if(!(r%2) && !(c%2)){
        int min = LEN*2,oi,oj;
        for(int i=1; i<=r; ++i){
            for(int j=1; j<=c; ++j){
                if((i+j)%2){
                    if(min > b[i][j]){
                        min = b[i][j];
                        oi=i; oj=j;
                    }
                }
            }
        }
        v[oi][oj]=1;
        search_path();
    }else
        search_path();
    cout<<endl;
}
int main()
{
    for(int i=0;i<LEN;++i)
        for(int j=0;j<LEN;++j)
            v[i][j]=1;
    cin>>r>>c;
    
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
            v[i][j]=0;
    
    for(int i=1; i<=r;++i)
        for(int j=1; j<=c; ++j)
            cin>>b[i][j];
    
    solve();
    return 0;
}
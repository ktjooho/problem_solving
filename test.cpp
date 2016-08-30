#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

struct Edge {
    int from,to;
};

Edge edge[2001];
int cnt[2001];
int check[2001];

bool cmp(const Edge& u, const Edge& v)
{
    if(u.from == v.from){
        return u.to < v.to;
    }else {
        return u.from < v.from;
    }
}

void dfs(int node){
    check[node]=true;
    
    for(int i=cnt[node-1];i<cnt[node];++i){
        int next = edge[i].to;
        if(check[next]==false)
            dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start]=true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=cnt[node-1];i<cnt[node];++i){
            int next = edge[i].to;
            if(check[next]==false){
                check[next] = true;
                q.push(next);
            }
        }
        
    }
}
int LIS()
{
    int ans = 0;
    int t[] = {10,20,20,30,40,50,60,60,70};
    
    vector<int> v(t,t+sizeof(t)/sizeof(int));
    
    
    vector<int>::iterator it = std::upper_bound(v.begin(), v.end(),20);
    
    cout<<(it-v.begin())<<endl;
    
    
    
    
    return ans;
}

int main()
{
    LIS();
    int n,m,start;
    scanf("%d%d%d",&n,&m,&start);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&edge[i].from,&edge[i].to);
        edge[i+m].from = edge[i].to;
        edge[i+m].to = edge[i].from;
    }
    m*=2;
    //정렬을 해서 넣음.
    sort(edge, edge+m, cmp);
    for (int i=0; i<m; i++) {
        cnt[edge[i].from] += 1;
    }
    //각 엣지별 시작 위치 인덱스 설정. 갯수가 몇개 있는지 세어서.
    for (int i=1; i<=n; i++) {
        cnt[i] += cnt[i-1];
    }
    return 0;
}
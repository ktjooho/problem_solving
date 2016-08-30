#include <vector>
#include <algorithm>
#include <cstdio>
#include <functional>


using namespace std;
using namespace placeholders;
typedef pair<int,int> PII;
//PII tree[500000];
int tree[500000][2];
int a[100005];
int n,m,l,r;

int _min(int a,int b){return min(a,b);}
int _max(int a,int b){return max(a,b);}
auto fmin = bind<int>(_min,_1,_2);
auto fmax= bind<int>(_max,_1,_2);

void init(int node, int start,int end,auto func)
{
    
    auto f=[](int s,int e, int n, auto func)->int{
        
        return 1;
    };
}
PII init(int node, int start, int end)
{
    if(start==end){
        tree[node].second=tree[node].first = a[start];
        return tree[node];
    }
    int mid = (start+end)/2;
    tree[node].first = min(init(node*2,start,mid).first,init(node*2+1, mid+ 1, end).first);
    tree[node].second = min(init(node*2,start,mid).second,init(node*2+1, mid+ 1, end).second);
    return tree[node];
}

PII query(int node,int start, int end, int left, int right)
{
   
    
    auto lamda = [](int start, int end, int node, auto func)->PII{
        
        return make_pair(1, 1);
    };
    if(right < start || left > end)
        return make_pair(1000000001, -1);
    
    if(left<=start && end<=right)
        return tree[node];
    
    int mid = (start+end)/2;
    
    PII ans;
    ans.first = min(query(node*2, start, mid, left, right),query())
    return make_pair(<#_T1 &&__t1#>, <#_T2 &&__t2#>)
    return min(find_min_node(node*2, start, mid, left, right),find_min_node(node*2+1,mid+1, end, left, right));
}
int ff(int a, int b){return 1;}
int main(){
    

    
    auto test = bind<int>(_min,_1,_2);
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    init(1,1,n);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&l,&r);
        printf("%d\n",find_min_node( 1, 1, n, l, r));
    }
    return 0;
}
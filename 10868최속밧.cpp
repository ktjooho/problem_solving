#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int tree[500000];
int a[100005];
int n,m,l,r;

int init(int node, int start, int end)
{
    if(start==end)
        return tree[node] = a[start];
    return tree[node] = min(init(node*2,start, (start+end)/2),init(node*2+1, (start+end)/2 + 1, end));
}
int find_min_node(int node,int start, int end, int left, int right)
{
    if(right < start || left > end)
        return 1000000001;
    if(left<=start && end<=right)
        return tree[node];
    return min(find_min_node(node*2, start, (start+end)/2, left, right),find_min_node(node*2+1, (start+end)/2+1, end, left, right));
}
int main(){
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
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
using namespace std;

#define MX 210
typedef unsigned short US;
int nCase,N,M,i,j,k,c[MX][16],s,ns,l,mx,pq,cq,v,ix;
US eq,t[MX][MX],cmp;

int main()
{
    scanf("%d",&nCase);
    while (nCase--)
    {
        scanf("%d%d",&N,&M);
        memset(t, 0, sizeof(t));
        memset(c, 0, sizeof(c));
      
        for(i=1;i<=N;++i)
        {
            scanf("%hd",&t[i][i]);
            
            //비트 갯수 확인
            for(cmp=1,j=0;j<16;++j,cmp<<=1)
                c[i][j] = c[i-1][j] + ((t[i][i]&cmp)?1:0);
            //OR연산 캐싱
            for(j=i-1;j>=1;j--)
                t[j][i]=t[j+1][i]|t[j][j];
        }
        
        //start algorithm
        eq=65535;
        mx=-1;
        s=1;
        
        //대략적인 알고리즘 :: 다음 강화까지 미리 구해서, 1의 값이 가장 많은 인덱스를 찾는 방식.
        //1. 현재 장비상수와 i번째 카드 그룹과 i+1번째 카드그룹을 AND 연산을 한 뒤에, 1의 비트 갯수를 센다.(갯수 : N)
        //2. 그리고 AND 연산을 한 장비상수의 비트를 순회하면서, 각 비트의 1의 갯수가 남은 강화횟수보다 적을 경우에는 N의 값을 하나 감소 시킨다.
        //3. N의 값이 가장 큰것을 다음 강화에 쓰일 장비상수로 결정.
        //1~3을 거치고나면 i번째 강화 후에 나오는 장비상수를 얻는다.
        
        
        
        for(ix=1;ix<=M-1;++ix)
        {
            l = N-M+ix;
            for(i=s;i<=l;++i)
            {
                for(j=i+1;j<=l+1;++j)
                {
                    cq = eq & t[s][i] & t[i+1][j];
                    
                    int cnt = bitset<16>(cq).count();
                    
                    for(cmp=1,k=0;k<16;++k,cmp<<=1)
                        if( (cmp&cq) && (c[N][k]-c[j][k] < M-s-1))
                            cnt--;
                    if(cnt > mx)
                    {
                        mx=cnt;
                        pq=cq;
                        ns=i+1;
                    }
                }
            }
            eq=pq;
            s=ns;
            mx=-1;
        }
        int ret = bitset<16>(eq&t[s][N]).count();
        printf("%d\n",ret);
    }
    return 0;
}
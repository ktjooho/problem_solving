#include <cstdio>
#include <cstdlib>
#include <set>
#include <bitset>
#include <cstring>

using namespace std;

int nCase, N, M;
//N-1 , N
unsigned short input[220];
unsigned short OR[220][220];

int main()
{
	scanf("%d",&nCase);
    
	while(nCase-->0)
	{
        set<int> table[2][220];
        memset(OR, 0, sizeof(OR));
		scanf("%d%d",&N,&M);
        
		for(int i=1; i<=N; ++i)
			scanf("%d",&input[i]);
        
		for(int i=1; i <= N; ++i)
		{
			int limit = N;
			for(int j=i; j<=limit; ++j)
			{
				unsigned short val = 0;
				for(int k=i; k<=j; ++k)
					val |= input[k];
				OR[i][j] = val;
			}
		}
        
        
        for(int i=0; i<N-M; ++i)
            table[0][i].insert(65535);
        
        int prevLimit=0, limit, prev, cur;
        int cnt=0;
		for(int i=1; i <=M; ++i,prevLimit=limit)
		{
            //            printf("mmmmmmmmmmmmmmmmmmm\n");
			//N-1의 범위
			//N의 가능 범위
			limit =  N-M+i;
			prev = (i+1)%2;
			cur = i%2;
            
            
            //N-M일 경우 0
            //N-M ~ N까지
			//N-1의 시작
			for(int j=i-1; j <= prevLimit; ++j)
			{
                int S = i < M ? j + 1 : limit;
				//N의 가능 범위
				for(int k=S; k <=limit; ++k)
				{
					//N-1에서 가지고 있는 값들 쳐집어넣음.
					for(auto equipConst : table[prev][j])
					{
                        ++cnt;
                        //                        printf("J:%d K:%d EQUIPCONST:%d OR[%d][%d]=%d\n",j,k,equipConst,j+1,k,OR[j+1][k]);
						table[cur][k].insert(equipConst & OR[j+1][k]);
					}
				}
			}
			for(int i=0; i <=prevLimit; ++i)
				table[prev][i].clear();
		}
        
		int max = -1;
        
		for(auto equipConst : table[cur][N])
		{
			int n =  bitset<16>(equipConst).count();
			if(equipConst > n)
				max = n;
		}
        printf("cnt:%d %d\n",cnt,max);
	}
	return 0;
}
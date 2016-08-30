#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace::std;

int n,m;
int a[105];
int b[105][105];
int sum[105];
int sum2[105];
int d[105][15];

void input()
{
    int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			d[i][j]=1000000000;
	d[0][0]=0;
}

void process()
{
	int i,j,k,o,x;
	double x1;
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)
		sum2[i]=sum2[i-1]+a[i]*a[i];
	
    
    //각 구간별 평균 정보를 미리 저장했기때문에, 비재귀적으로 처리가 가능해진것임.
    for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			x1=(double)(sum[j]-sum[i-1])/(j-i+1);
			x=x1;
			if(x+1-x1<x1-x)
				x++;
			b[i][j]=(j-i+1)*x*x;
			b[i][j]-=2*(sum[j]-sum[i-1])*x;
			b[i][j]+=sum2[j]-sum2[i-1];
		}
	}
    
    //예외처리 부분이있네.
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j==1)
				d[i][j]=b[1][i];
			else
			{
				d[i][j]=d[i][j-1];
                
                //내껀 메모이제이션으로 했는데..
                
                
                //갈라서 확인하는 부분임.
				for(k=1;k<i;k++)
				{
					if(d[i][j]>d[k][j-1]+b[k+1][i])
						d[i][j]=d[k][j-1]+b[k+1][i];
				}
			}
		}
	}
}

void output()
{
	printf("%d\n",d[n][m]);
}

int main()
{
	int i,c;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		input();
		process();
		output();
	}
	return 0;
}
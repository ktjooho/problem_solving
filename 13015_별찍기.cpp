#include <cstdio>

int n,h,w;
char star[1000][1000];

void makeStar(int n)
{
    h = n+n-1;
    w = 2*n + (n-1)+(n-1)-1;
    
    for(int i=0; i<h; ++i)
        for(int j=0;j<w;++j)
            star[i][j]=' ';
   
    for(int i=0; i<w; ++i){
        if(i <n || i >= w-n){
            star[0][i]='*';
            star[h-1][i]='*';
        }
    }
    
    for(int i=1;i<n-1;++i){
        star[i][i] = '*';
        star[i][n+i-1] = '*';
        
        star[i][w-i-1] = '*';
        star[i][w-i] = '\0';
        star[i][w-n-i ] = '*';
        
        star[h-i-1][i] = '*';
        star[h-i-1][w-i-1] = '*';
        star[h-i-1][w-i] = '\0';
        star[h-i-1][n+i-1] = '*';
        star[h-i-1][w-n-i ] = '*';
    }
    star[h/2][n-1] = '*';
    star[h/2][w/2] = '*';
    star[h/2][w-n] = '*';
    
    star[h/2][w-n+1] = '\0';
}

int main()
{
    scanf("%d",&n);
    makeStar(n);
    for(int i=0; i<h; ++i)
    {
        printf("%s",star[i]);
        printf("\n");
    }
    return 0;
}
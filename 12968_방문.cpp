#include <cstdio>

int r,c,k;

int main()
{
    scanf("%d%d%d",&r,&c,&k);
    
    if((r*c) % 2){
        if(k>1)
            printf("0\n");
        else
            printf("1\n");
    }else{
        printf("1\n");
    }
    
    
    
    return 0;
}
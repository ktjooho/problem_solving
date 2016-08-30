#include <cstdio>
#include <cstring>

char s[51];

char table[53][53];

int solve(int pos)
{
    if(pos >= strlen(s))
        return 1;
    
    for(int len=4; len <= strlen(s);len+=4){
        
        if(!strncmp(table[len/4], s+pos, len)){
            return solve(pos+len);
        }
    }

    return 0;
}

int main()
{
    for(int i=1; i<=13; i++)
    {
        int n = i;
        
        for(int j=0; j<n; ++j)
            table[i][j] = 'w';
        for(int j=n; j<2*n; ++j)
            table[i][j] = 'o';
        for(int j=2*n; j<3*n; ++j)
            table[i][j] = 'l';
        for(int j=3*n; j<4*n; ++j)
            table[i][j] = 'f';
    }
   
    scanf("%s",s);
 
    if(strlen(s)%4)
    {
        printf("0\n");
        return 0;
    }
        
    printf("%d\n",solve(0));
    return 0;
}
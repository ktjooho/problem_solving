#include <cstdio>
#include <cstdlib>
#include <cstring>

int n,s[51],ans;
char str[51];

int main()
{
    scanf("%d",&n);
    
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&s[i]);
        str[s[i]] = 'a'+i;
    }

    char c = 'a';
    ans++;
    
    for(int i=1; i<n; ++i)
    {
        str[s[i]] = c;
        
        if(strcmp(str+s[i-1] , str+s[i]) >= 0)
        {
            c++;
            str[s[i]] = c;
            ans++;
        }
        
    }
    printf("%d\n",ans);
    return 0;
}
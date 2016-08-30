#include <cstdio>
#include <cstdlib>
#include <cstring>

int len,sa[51];
char s[51],str[51];

/*
    접미사의 접미사는 접미사다.
    suffix, prefix.
 
 
 */
int main()
{
    scanf("%s",s);
    len = strlen(s);
    
    for(int i=0; i<len; ++i)
        sa[i] = len - i-1;
    
    for(int i=0; i<len-1; ++i)
    {
        for(int j=i+1;j<len;++j){
            if(strcmp(s+sa[i],s+sa[j]) > 0)
            {
                int temp = sa[i];
                sa[i] = sa[j];
                sa[j] = temp;
            }
        }
    }
    
    for(int i=0; i<len; ++i)
        str[sa[i]] = 'a' + i;
    
    char c = 'a';
    for(int i=1; i<len; ++i)
    {
        str[sa[i]] = c;
        
        if(strcmp(str + sa[i-1], str + sa[i])>=0)
        {
            c++;
            str[sa[i]]=c;
        }
    }
    
    if(!strcmp(str, s)){
        printf("0\n");
    }else
        printf("1\n");
    
    
    
    return 0;
}
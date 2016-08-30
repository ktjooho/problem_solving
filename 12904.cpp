#include <cstdlib>
#include <cstdio>
#include <cstring>




int main()
{
    char s[1005],t[1005];
    
    scanf("%s",s);
    scanf("%s",t);
    
    int t_len = strlen(t);
    int s_len = strlen(s);
    
    for(int i=t_len-1; i>=s_len; --i)
    {
       // printf("T:%s\n",t);
        if(t[i]=='A'){
            t[i] = '\0';
        }else{
            t[i] = '\0';
            int len = strlen(t);
            char s;
            //printf("prev t[%s]\n",t);
            for(int j=0; j<len/2; ++j){
                s = t[j];
                t[j] = t[len-1-j];
                t[len-1-j]=s;
            }
           // printf("after t[%s]\n",t);
        }
    }
    //printf("%s\n",t);
    printf("%d\n",!strcmp(s,t));
    
    
    
    
    
    return 0;
}
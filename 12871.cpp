#include <string.h>
#include <stdio.h>


char s1[3000];
char s2[3000];
char _s1[51];
char _s2[51];
char temp[500];

//주기를 구하거나 합치는 방식

int main()
{
    scanf("%s",s1);
    strcpy(_s1, s1);
    
    scanf("%s",s2);
    strcpy(_s2, s2);
    
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    size_t total_length = len_s1 * len_s2;
    
    while (strlen(s1)<total_length)
    {
        strcat(s1, _s1);
    }
    while (strlen(s2)<total_length) {
        strcat(s2, _s2);
    }
    
    if(!strcmp(s1, s2))
        printf("1\n");
    else
        printf("0\n");
    
    
    return 0;
}
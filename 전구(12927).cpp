#include <cstdio>
#include <iostream>
#include <string>


using namespace std;

int main()
{
    int ans=0;
    string str;
    cin>>str;
    
    for(int i=0;i<str.length();++i)
    {
        if(str[i]=='Y')
        {
            ans++;
            for(int j=i; j<str.length();++j)
            {
                if( ((j+1) % (i+1)) == 0)
                {
                    if(str[j]=='Y')
                        str[j] = 'N';
                    else
                        str[j] = 'Y';
                }
            }
            
        }
        
        
    }
    printf("%d\n",ans);
    
    
}
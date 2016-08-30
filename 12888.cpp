#include <cstdio>
#include <cstdlib>

unsigned long long table[100];

int main()
{
    int N;
    scanf("%d",&N);
    table[0] = 0;
    table[1] = 1;
    
    for(int i=2; i<=60; ++i)
    {
        table[i] = 2 * table[i-1] + 1;
    }
    
    printf("%llu\n",table[N]);
    
    return 0;
}
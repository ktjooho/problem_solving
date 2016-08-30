//
//  main.cpp
//  10220
//
//  Created by sungjuho on 2016. 5. 17..
//  Copyright © 2016년 sungjuho. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

int nTestCase,N,seq[101];
int ans[101];

//곱 결과도 n이고
//갯수 합도 n 인게
//self represent

int check()
{
    for(int i=0; i<N; ++i)
    {
        int c = 0;
        for(int j=0; j<N;++j)
        {
            if(seq[j]==i)
                ++c;
        }
        if(c!=seq[i])
            return 0;
    }
    for(int i=0; i<N; ++i)
        printf("%d ,",seq[i]);
    printf("\n");
    return 1;
}


int solove(int idx,int r)
{
    int n=0;
    
    if(idx==N-1)
    {
        seq[idx] = 0;
        return check();
    }
    
    for(int i=0; i<=r; ++i)
    {
        seq[idx] = i;
        n+=solove(idx + 1,r-i);
    }
    return n;
}


int main()
{
    for(int i=0; i<=101;++i)
        ans[i]=1;
    ans[1]=ans[2]=ans[3]=ans[6]=0;
    ans[4]=2;
    
    
    scanf("%d",&nTestCase);
    
    while (nTestCase--)
    {
        scanf("%d",&N); // 수열 길이 N
        printf("%d\n",ans[N]);
    }
    
    return 0;
}

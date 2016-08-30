//
//  main.cpp
//  10219
//
//  Created by sungjuho on 2016. 5. 18..
//  Copyright © 2016년 sungjuho. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

int H,W,T;
char b[12][12];

void printBoard()
{
    for (int i=0; i<H; ++i) {
        printf("%s\n",b[i]);
    }
}
void flip()
{
    int hw = W/2,temp;
    
    for(int i=0; i<H; ++i)
    {
        for(int j=0; j<hw; ++j)
        {
            temp = b[i][j];
            b[i][j] = b[i][W-j-1];
            b[i][W-j-1] = temp;
        }
    }
}
int main()
{
    //X대칭
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&H,&W);
        for(int i=0; i<H;++i)
            scanf("%s",b[i]);
        flip();
        printBoard();
        
    }
    
    
    return 0;
}

//
//  main.cpp
//  GRID
//
//  Created by sungjuho on 2014. 8. 2..
//  Copyright (c) 2014년 sungjuho. All rights reserved.
//

#include <iostream>
#include <cstdio>


#define N 1000

unsigned int table[4][N];
unsigned int nCase,W;

int solve(int h, int w, int num);

int solve(int h, int w, int num)
{
    printf("ROW:%d COL:%d\n",h,w);
    
    /*
    if(h>=4 && w>=W)
    {
        printf("도착 : H:%d W:%d\n",h,w);
        return 1;
    }
     */
    
    
    if(h>=4 || w >= W )
    {
        printf(">>>OUT h:%d w:%d \n",h,w);
        return 0;
    }
    
    if(num==2*W)
    {
        printf("RETURN : %d \n",num);
        return 1;
    }
    
    
    
    unsigned int& value = table[h][w];
    
    if(value)
    {
        printf("ALREAY ROW[%d]COL[%d]=%d\n",h,w,table[h][w]);
        return value;
    }
    
    
    if(w <= W-2)
    {
        
        value += solve(h, w+2,num+1) + solve(h+1, w,num+1);
        
    }
    if(h <= 2)
    {
        value += solve(h+2, w,num+1)+solve(h, w+1,num+1);
        
    }
    printf("RETURN ROW:%d COL:%d Value:%d\n",h,w,value);
    return value;
}

int main(int argc, const char * argv[])
{
    scanf("%d",&nCase);
    while(nCase-->0)
    {
        scanf("%d",&W);
        printf("%d\n",solve(0, 0,1));
        
    }
    return 0;
}


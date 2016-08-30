//
//  main.cpp
//  FLAPPY
//
//  Created by sungjuho on 2014. 9. 14..
//  Copyright (c) 2014년 sungjuho. All rights reserved.
//
/*
 
 2
 2 10
 ...#.#..#.
 @#........
 5 9
 ....#....
 ..#.#..#.
 @.#.#..#.
 ..#.#..#.
 ..#....#.

 
 
 */
#include <cstdio>

#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

int nCase,H,W,result;

short table[20][1000][1000];

int main(int argc, const char * argv[])
{
    
    scanf("%d",&nCase);
    while (nCase-->0)
    {
        scanf("%d%d",&H,&W);
        char board[20][1000];
        for(int i=0; i <H; ++i)
        {
            scanf("%s",board[i]);
//            printf("]] %s\n",board[i]);
            for(int j=0; j < W; ++j)
                table[i][j][0] = 0;
        }
        
        for(int i=0; i<H; ++i)
        {
            if(board[i][0]=='@')
            {
                table[i][0][0] = 1;
                table[i][0][1] = 0;
            }
            else
                table[i][0][0] = 0;
        }
        bool check = true;
        result = 1;
        
        for(int i=0; i <W-1 && check; ++i)
        {
            check = false;
//            printf("m:%d\n",result);
            for(int j=0; j <H; ++j)
            {
                if(table[j][i][0]>0)
                {
//                    printf("[%d][%d](%d) 방문\n",j,i,table[j][i][0]);
                    for(int k=0; k<table[j][i][0]; ++k)
                    {
//                        printf("속도 : %d\n",table[j][i][k+1]);
                        //UP
                        int up = MAX(j-4, 0);
                        int speed = 0;
                        
                        if(board[up][i+1]=='.')
                        {
                            speed = 0;
                            bool flag = false;
                            for(int x=1; x <= table[up][i+1][0]; ++x)
                                if(table[up][i+1][x] == speed)
                                    flag = true;
                            
                            if(!flag)
                            {
                                int idx = ++table[up][i+1][0];
                                table[up][i+1][idx] = speed;
                                check = true;
                                //printf("UP! [%d][%d][%d]\n",up,i+1,idx);
                            }
                            
                        }
                        
                        //DOWN
                        int down = MIN(j+table[j][i][k+1]+1,H-1);
                        //printf("UP:%d DOWN:%d\n",up,down);
                        if(board[down][i+1]=='.')
                        {
                            speed = table[j][i][k+1] + 1;
                            bool flag = false;
                            for(int x=1; x <= table[up][i+1][0]; ++x)
                                if(table[up][i+1][x] == speed)
                                    flag = true;
                            if(!flag)
                            {
                                int idx = ++table[down][i+1][0];
                                table[down][i+1][idx] = speed;
                                check = true;
//                                printf("DOWN [%d][%d][%d] 속도[%d]\n",down,i+1,idx,table[down][i+1][idx]);

                            }
                        }
                        
                    }
                }
            }
            if(check) result++;
            
        }
        
        printf("%d\n",result);
        //열 단위로 탐색하면서
        //가능성을 체크 해준다.
        //속도를 표시해줘야됨
        
    }

    return 0;
}


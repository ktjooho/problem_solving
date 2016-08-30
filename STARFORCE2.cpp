//
//  main.cpp
//  STARFORCE2
//
//  Created by sungjuho on 2014. 12. 28..
//  Copyright (c) 2014년 sungjuho. All rights reserved.
//
#include <bitset>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>



using namespace std;



int nCase,N,M;
int checkBit[210][16];
unsigned short value[210][210][3];
vector<unsigned short> input;
int solve(int upgradeIdx, const set<pair<int,unsigned short>>& checkSet)
{
    if(upgradeIdx > M)
    {
        int maxVal=0;
        for(auto checkPair : checkSet)
        {
            int val = bitset<16>(checkPair.second).count();
            if(val>maxVal)
                maxVal=val;
        }
        return maxVal;
    }
    
    int limit = N-M + upgradeIdx;

    set<pair<int, unsigned short>> nextCheckSet;
    
    int minVal = 25;
    int minLostVal = 25;
    

    //강화값을 인덱스로 관리해야된다.
    //(강화값 - 시작인덱스)
    //그리고 이전에 비트없는 것에 대해서도, 고려할수있어야함.
    //
    
    for(auto checkPair : checkSet)
    {
        unsigned short cardOR = 0x0;
        minVal = 25;
        minLostVal = 25;
        
        for(int i=checkPair.first; i<=limit; ++i)
        {
            int val = 0, lostVal;
            
            cardOR |= input[i];
            
            for(int j=0; j<16; ++j)
            {
                if(checkBit[N][j]<M)continue;
                
                if(!(checkBit[i][j] - checkBit[checkPair.first-1][j])) val++;
                
                if(checkBit[N][j] - checkBit[i][j] < M - upgradeIdx) val++;
            }
//            printf(" start:%d next:%d val:%d\n",checkPair.first, i+1, val);
            lostVal = 16 - bitset<16>(cardOR & checkPair.second).count();
            if(minVal >= val)
			{
                minVal = val;
                
				if(minLostVal > lostVal)
					minLostVal = lostVal;
                
			}
            //value에서 다중중복이 될수도있다..
            value[checkPair.first][i][0] = cardOR;
            value[checkPair.first][i][1] = val;
            value[checkPair.first][i][2] = lostVal;
        }
    }
    for(auto checkPair : checkSet)
    {
        for(int i=checkPair.first; i<=limit; ++i)
        {
            if(
               value[checkPair.first][i][1]==minVal
               &&
               value[checkPair.first][i][2]==minLostVal
               )
            {
                printf("UPGRADE INDEX : %d, Start:%d next:%d minVal:%d minLostVal:%d VAL:%d Or:%d\n",upgradeIdx,checkPair.first,i+1,minVal,minLostVal,checkPair.second,value[checkPair.first][i][0]);
                nextCheckSet.insert(make_pair(i+1, checkPair.second&value[checkPair.first][i][0]));
            }
        }
    }
        
    
    return solve(upgradeIdx+1, nextCheckSet);
}
int main(int argc, const char * argv[])
{
    input.reserve(210);
    scanf("%d",&nCase);

    while (nCase-->0)
    {
        scanf("%d%d",&N,&M);
        unsigned short n;
        
        for(int i=1; i<=N; ++i)
        {
            scanf("%hd",&n);
//            input[i]=n;
            input.push_back(n);
        }
        
        int result = -1;
        
        for(int cnt=0; cnt < 2; ++cnt)
        {
            memset(checkBit, 0, sizeof(checkBit));
            
            for(int i=1; i<=N; ++i)
            {
                unsigned short cmp = 0x1;
                
                for(int j=0; j<16; ++j,cmp<<=1)
                    checkBit[i][j] = checkBit[i-1][j] + ((input[i]&cmp) ? 1:0);
            }
            for(int i=0; i<16; ++i)
                if(checkBit[N][i]<M)
                    for(int j=1; j<=N;++j)
                        checkBit[j][i] = 0;
            
        
            set<pair<int, unsigned short >> checkSet;
            checkSet.insert(make_pair(1, 65535));
            
            int ret = solve(1, checkSet);
            
            if(ret > result)
                result = ret;
            reverse(input.begin(), input.end());
        }
        
        printf("%d\n",result);
        
    }
    return 0;
}


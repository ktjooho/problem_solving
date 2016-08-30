#include <cstdio>
#include <bitset>
#include <cstring>
#include <set>
#include <list>

using namespace std;

#define MX 210

int N,M,nCase,OR[MX][MX],i,j,k;
set<int> sIdx[2];
set<int> eq[2][210];

int main()
{
    scanf("%d",&nCase);
    
    while (nCase--)
    {

        scanf("%d%d",&N,&M);
        
        for(i=1;i<=N;++i)
        {
            scanf("%d",&OR[i][i]);
            for(j=i-1;j>=1;--j)
                OR[j][i]=OR[j+1][i]|OR[j][j];
        }
        
        for(i=1; i<=N; ++i)
            printf("%s\n",bitset<16>(OR[i][i]).to_string().c_str());
        sIdx[0].insert(0);
        
        eq[0][0].insert(65535);
        
        int next,prev;
        
       // const char * str = bitset<16>(320).to_string().c_str();
       // printf("STR : %s\n",str);
        for(i=1;i<=M;++i)
        {
            next = (i)%2;
            prev = (i+1)%2;
            //printf("TEL:%d\n",sIdx[prev].size());
            for(auto idx : sIdx[prev])
            {
              //  printf("IDX:%d EQ SIZE : %d\n",idx,eq[prev][idx].size());
                for(auto e : eq[prev][idx])
                {
                //    printf("%s\n",bitset<16>(e).to_string().c_str());
                    
                    for(k=idx+1;k<=N-M+i;++k)
                    {
                        bool bSkip = false;
                        int ne = e & OR[idx+1][k];
                       
                        for(j=idx+1;j<k; ++j)
                        {
                            for(auto pe : eq[next][j])
                            {
                                if(!((pe&ne)-ne))
                                {
                                    bSkip = true;
                                   // printf("SKIP!!1\n");
                                    break;
                                }
                            }
                        }
                        if(bSkip) continue;
                        eq[next][k].insert(ne);
                        sIdx[next].insert(k);
                       // printf("NEXT IDX : %d VALUE : %d \n",k,ne);
                    }
                }
                eq[prev][idx].clear();
            }
            
            
            for(auto idx : sIdx[next])
            {
                for(auto e1 : eq[next][idx])
                {
                    auto e2 = std::begin(eq[next][idx]);
                    while (e2!=std::end(eq[next][idx]))
                    {
                      //  printf("E1 : %d E2 : %d \n",e1,*e2);
                        if(e1 == *e2)
                        {
                            e2++;
                            continue;
                        }
                        //printf("fuck IDX:%d E1:%d E2:%d\n",idx,e1,*(e2));
                        if(!( (e1&*e2)-*e2 ) )
                            e2 = eq[next][idx].erase(e2);
                        else
                            e2++;
                    }
                }
            }
             
            
            auto idxIter = std::begin(sIdx[next]);
            while (idxIter!=std::end(sIdx[next]))
            {
                int idx1 = *idxIter;
                
                auto e1 =  std::begin(eq[next][idx1]);
                
                while (e1 != std::end(eq[next][idx1]))
                {
                    if(eq[next][idx1].size()>1)
                    {
                      //  printf("EQ SIZE:%d\n",eq[next][idx1].size());
                        
                        //for(auto es : eq[next][idx1])
                          //  printf("%s\n",bitset<16>(es).to_string().c_str());
                        
                    }
                 //   printf("체크 IDX1 : %d E1: %d\n",idx1,*e1);
                    bool bErase = false;
                    for(auto idx2 : sIdx[next])
                    {
                        if(idx2>=idx1)
                            continue;
                        for(auto e2 : eq[next][idx2])
                        {
                            if(!((*e1 & e2)-*e1))
                            {
                             //   printf("DEL E1 : %d E2: %d IDX1:%d IDX2: %d\n",*e1,e2,idx1,idx2);
                                bErase = true;
                                break;
                            }
                        }
                        if(bErase)   break;
                    }
                    if(bErase)
                        e1 = eq[next][idx1].erase(e1);
                    else
                        e1++;
                }
                if(!eq[next][idx1].size())
                {
                    idxIter = sIdx[next].erase(idxIter);
                    //printf("IDX1 : %d 삭제\n",idx1);
                }
                else
                    idxIter++;
            }
            
            sIdx[prev].clear();
            int sum = 0;
            for(auto idx : sIdx[next])
            {
                printf(">>>>I:%d %d size:%d \n",i,idx,eq[next][idx].size());
                for(auto e : eq[next][idx])
                    printf("%s\n",bitset<16>(e).to_string().c_str());
                sum += eq[next][idx].size();
            }
            printf("[IDX : %d] SIZE :%d \n",i,sum);
        }
             
        int max = 0;
        for(auto idx : sIdx[next])
            for(auto e : eq[next][idx])
                if(bitset<16>(e).count() > bitset<16>(max).count())
                    max = e;
        printf("%d\n",bitset<16>(max).count());
                
        
        //Algorithm
        //-------------------------------
        //0. 자료구조 선정.
        // --> 크기를 알 수 있는 복수개의 시작인덱스와 각 시작인덱스는 갯수를 알 수 없는 복수개의 장비 상수를 가질 수 있는 구조임.
        //1. 종료 인덱스별, 포함관계 배제.
        // -->
        //2. 동일한 이전 장비상수별, 포함관계 배제.
        // -->
        //3.
        // -->
        //4.
        //-------------------------------
        
        ///
        
        //
        
        ///
        
        ///
        
        ///
        
        ///
    }

    return 0;
}


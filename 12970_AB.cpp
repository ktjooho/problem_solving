#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

int n,k;
vector<int> abc[3];

void printSeq(int i, int numA, int numB, int ck, string str)
{
    if(i==n)
    {
        if(ck==k){
            cout<<str<<endl;
            exit(0);
        }
        return ;
    }else{
        if(ck>=k){
            str.push_back('C');
            printSeq(i+1,numA,numB,ck,str);
            str.pop_back();
        }else{
            //A선택
            //줄이는 갯수
        
            int d = n - i -1;
            int afterCK_a = d + ck - numA - numB;
            int afterCK_b = d + ck - numB;
           
            //A(A와 B 고려)
            
            //B(B만 고려)
            if(afterCK_a<=k && afterCK_a > ck)
            {
                str.push_back('A');
                printSeq(i+1,numA+1,numB,afterCK_a,str);
                str.pop_back();
            }
            if(afterCK_b<=k && afterCK_b > ck)
            {
                str.push_back('B');
                printSeq(i+1,numA,numB+1,afterCK_b,str);
                str.pop_back();
            }
            
            //현재 위치에서 못만들면 탐색안하도록
            int len = n-i;
            int remainK = k - ck;
            
            if( (len*len)/3 >= remainK)
            {
                str.push_back('C');
                printSeq(i+1, numA,numB, ck,str);
                str.pop_back();
            }
        }
        
    }
    return ;
}

int main()
{
    //n-1 +
    
    scanf("%d%d",&n,&k);
    
    //A의 갯수 * B의 갯수
    string str="";
    int limit = (n*n)/3;
   // printf("LMIT:%d\n",limit);
    if(k > limit)
        printf("-1\n");
    else
        printSeq(0,0,0,0,str);
    return 0;
}
//
//  main.cpp
//  BRIDGE
//
//  Created by sungjuho on 2014. 8. 10..
//  Copyright (c) 2014년 sungjuho. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

long long combination(int l, int r)
{
    
    long long result = 1;
    long long n=1;
    
    while(r)
    {
        result *= r--;
        
    }
    std::cout<<"result"<<result<<endl;
    while (l) {
        n *= l--;
    }
    
    result = result / n;
    
    
    
    return result;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    //std::cout << "Hello, World!\n";
    std::cout<<combination(13, 29)<<std::endl;
    return 0;
}


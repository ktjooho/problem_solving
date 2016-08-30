#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,a[1001];

vector<int> actual_seat;


int main()
{
    actual_seat.push_back(2000000000);
    cin>>n>>d;
    
    for(int i=0; i<n; ++i)
        cin>>a[i];
    
    for(int i=0;i<n;++i)
    {
        int seat_pos;
        
        if(a[i]<= actual_seat[0] - d)
        {
            seat_pos = a[i];
        }else{
            for(int j=0; j < actual_seat.size()-1; ++j){
                
                seat_pos = max(a[i], actual_seat[j]+d);
                
                if(seat_pos <= actual_seat[j+1]-d){
                    break;
                }
            }
            
        }
        actual_seat.push_back(seat_pos);
        std::sort(actual_seat.begin(), actual_seat.end());
        cout<<seat_pos<<' ';
    }
    
    cout<<'\n';
        
    
    
    return 0;
}
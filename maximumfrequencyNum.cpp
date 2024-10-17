#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[]={1,2,2,2,3,3,3,-1,-1,1,-2,-3,-3,66,55,66,55};
    unordered_map<int,int>m;
    for(int i:arr)
    {
        m[i]++;
    }
    int max = -9999999;
    for(auto i:m)
    {
        if(i.second > max)
        {
            max=i.second;
        }
    }
    cout<<max<<endl;
}
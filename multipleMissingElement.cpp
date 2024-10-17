#include <iostream>
using namespace std;
void missing_elements(int arr[],int d,int size)
{
    int sum =arr[0];
    int end = arr[size-1];
    int j=0;
    cout<<sum<<" ";
    while(end>sum)
    {
        sum = sum + d;
        if(j>= size||sum!=arr[j])
        {
            cout<<" "<<sum<<" ";
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 5, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 1;
    int end = 10;
    missing_elements(arr, 1,n);
    return 0;
}

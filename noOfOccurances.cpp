#include <iostream>
#include <vector>
using namespace std;
int countOccurrences(vector < int > arr, int x) 
{
    int count=0;
    int l=0,e=arr.size(),mid=(l+e)/2;
    while(l<e)
    {
        if(arr[mid]==x)
        {
            //we check both sides and run loop
            int n=mid;
            while(n>=l&&arr[n]==x)
            {
                count++;
                n--;
            }
            int m=mid+1;
            while(m<=e&&arr[m]==x)
            {
                count++;
                m++;
            }
            break;
        }
        else if (arr[mid]>x)
        {
            e=mid;
        }
        else{
            l=mid+1;
        }
    }
    return count;
}

int main() {
    std::vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;
    int count = countOccurrences(arr, x);
    std::cout << "Count of " << x << ": " << count << std::endl;
    return 0;
}
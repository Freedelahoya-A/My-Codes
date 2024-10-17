#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
int main()
{
   unordered_map<string,int> m;
   string f;
   cout<<"Enter a sentence"<<endl;
   getline(cin,f);
   string word;
   f=f+' ';
   for(char c:f)
   {
    if(c==' ')
    {
    if(!word.empty())
    {
        m[word]++;
        word="";
    }
    }
    else
    {
        word+=c;
    }
   }
   for(auto i:m)
   {
    cout<<i.first<<" "<<i.second<<endl;
   }
return -999;
}
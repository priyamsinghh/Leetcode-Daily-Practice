//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> c;
         for(int i=0;i<x.length();i++)
         {
             if(c.empty())
             {
                 c.push(x[i]);
             }
             else if(c.top()=='('&& x[i]==')'||c.top()=='['&&x[i]==']'||c.top()=='{'&&x[i]=='}')
             {
                 c.pop();
             }
             else
             {
                 c.push(x[i]);
             }
         }
         if(c.empty()){
             return true;
         }
         return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
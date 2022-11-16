//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
          unordered_map<char,int> mp;

       

        int ans=0;

        for(int i=0;i<s.size();i++){

            for(int j=i;j<s.size();j++){

                mp[s[j]]++;

                 int max=INT_MIN;

        int min=INT_MAX;

                for(auto it:mp){

                if(it.second>max){

                    max=it.second;

                }

                if(it.second<min)

                min=it.second;

            }

              ans+=max-min;

            }

           

            mp.clear();

        }

        return ans;

    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
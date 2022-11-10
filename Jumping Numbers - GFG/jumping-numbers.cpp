//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long ans;

    void solve(long long i,long long x){

        if(i>x){

            if(i/10<=x)

            ans=max(ans,i/10);

            return ;

        }

        if(i%10==0){

            solve(i*10+1,x);

        }

        else if(i%10==9){

            solve(i*10+8,x);

        }

        else{

            solve(i*10+i%10-1,x);

            solve(i*10+i%10+1,x);

        }

    }

    long long jumpingNums(long long X) {

        // code here

        ans=1;

        for(int i=1;i<=9;i++){

            solve(i,X);

        }

        return ans;

    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
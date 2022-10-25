//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    

    //Function to find maximum of each subarray of size k.

    vector <int> max_of_subarrays(int *arr, int n, int k)

    {

        // your code here

        deque<int>dq;

        vector<int>vec;

        int pre=0;

        for(int post=0;post<n;post++){

            while(!dq.empty() && arr[post]>=arr[dq.back()]){

                dq.pop_back();

            }

            dq.push_back(post); // here we are storing indexes in deque in decreasing ordere of values in given array

            if(post-pre+1<k) // ignore below if current size covered is less than k

                continue;

            vec.push_back(arr[dq.front()]);

            

            if(pre==dq.front()) // remove element from deque if element that has to be removed is fat front of deque

                dq.pop_front();

            pre++;

        }

        return vec;

    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
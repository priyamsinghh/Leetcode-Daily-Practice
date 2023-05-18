//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    queue<pair<int,pair<int,int>>> q; // {{steps,{row,col}}
        vector<vector<int>>vis(N+1,vector<int>(N+1,0));
        
        q.push({0,{KnightPos[0]-1,KnightPos[1]-1}});
        
        vis[KnightPos[0]-1][KnightPos[1]-1]=1;
        
        int d1[8]={ 2, 2, -2, -2, 1, 1, -1, -1 };
        int d2[8]={ -1, 1, 1, -1, 2, -2, 2, -2 };
        
        while(!q.empty()){
            auto it = q.front();
            int steps=it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            if(row==TargetPos[0]-1 && col==TargetPos[1]-1){
                return steps;
            }
            
            for(int i=0;i<8;i++){
                int nrow = d1[i]+row;
                int ncol = d2[i]+col;
                
                if(nrow>=0 && nrow<=N && ncol>=0 && ncol<=N && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
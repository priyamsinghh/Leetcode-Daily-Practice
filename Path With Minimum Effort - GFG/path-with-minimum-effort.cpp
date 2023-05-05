//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        q.push({0,{0,0}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
           
            if(r == n - 1 && c == m-1)
                return dis;
            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow<n && nrow >= 0 && ncol < m && ncol>=0)
                {
                    int eff = max(abs(heights[r][c] - heights[nrow][ncol]), dis);
                    if(eff < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = eff;
                        q.push({eff,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
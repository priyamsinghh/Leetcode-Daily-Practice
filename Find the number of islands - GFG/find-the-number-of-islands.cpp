//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  void bfs(int r, int c , vector<vector<int>>&vis, vector<vector<char>>&grid)
  {
      vis[r][c]= 1;
      int n = grid.size();
      int m = grid[0].size();
      queue<pair<int,int>>q;
      q.push({r,c});
      while(!q.empty())
      {
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          for(int drow=-1;drow<=1;drow++)
          {
              for(int dcol=-1;dcol<=1;dcol++)
              {
                int nrow = r+drow;
                int ncol = c+dcol;
                if(nrow>=0 && nrow<n && ncol>=0&& ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] =='1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
              }
          }
      }
  }
  public:
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int cnt = 0;
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
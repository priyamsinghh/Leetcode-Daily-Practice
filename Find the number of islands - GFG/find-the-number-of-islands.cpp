//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
  /*
  int drow[8]={0,-1,-1,-1,0,1,1,1};
    int dcol[8]={-1,-1,0,1,1,1,0,-1};
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
            for(int i=0;i<8;i++)
            {
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0&& ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] =='1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
    
      }
  }*/
  void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid)
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    
    // int dcol[8]={0,-1,-1,-1,0,1,1,1};
    // int drow[8]={-1,-1,0,1,1,1,0,-1};
   
    //     for(int i=0;i<8;i++)
        for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            int nrow = row + i;
            int ncol = col + j;
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                 dfs(nrow,ncol,vis,grid);   
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
                    dfs(i,j,vis,grid);
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
class Solution {
public:
    vector<int> ans;
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid)
    {
        if(i==m)
        {
            if(j>=0&&j<n)
            {
                ans.push_back(j);
                return ;
            }
            else
            {
                ans.push_back(-1);
                return ;
            }
        }
        if((grid[i][j]==1&&j==n-1)||(grid[i][j]==-1&&j==0))
        {
            ans.push_back(-1);
            return ;
        }
        if((grid[i][j]==1&&grid[i][j+1]==-1)||(grid[i][j]==-1&&grid[i][j-1]==1))
        {
            ans.push_back(-1);
            return;
        }
        if(grid[i][j]==1)
        {
            dfs(i+1,j+1,m,n,grid);
        }
        else
        {
            dfs(i+1,j-1,m,n,grid);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=0;j<n;j++)
        {
            dfs(0,j,m,n,grid);
        }
        return ans;
    }
};
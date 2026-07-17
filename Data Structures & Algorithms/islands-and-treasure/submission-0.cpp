class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int count)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==-1 || count>grid[i][j])
        {
            return;
        }
        grid[i][j]=min(grid[i][j],count);
        dfs(grid,i+1,j,count+1);
        dfs(grid,i-1,j,count+1);
        dfs(grid,i,j+1,count+1);
        dfs(grid,i,j-1,count+1);

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    int count=0;
                    dfs(grid,i,j,count);
                }
            }
        }
    }
};

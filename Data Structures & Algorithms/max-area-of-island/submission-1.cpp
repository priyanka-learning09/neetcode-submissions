class Solution {
public:
    int maxcount=0;
    void dfs(vector<vector<int>> &grid,int i,int j,int &count)
    {
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j]==0 )
        {
           
            return;
        }
        count++;
        grid[i][j]=0;
        dfs(grid,i+1,j,count);
        dfs(grid,i-1,j,count);
        dfs(grid,i,j+1,count);
        dfs(grid,i,j-1,count);
        maxcount=max(maxcount,count);


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.empty() || grid.size()==0 || grid[0].size()==0)
        {
            return 0;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;

                    dfs(grid,i,j,count);
                }
            }
        }
        return maxcount;
    }
};

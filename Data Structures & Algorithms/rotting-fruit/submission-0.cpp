class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &time,int i,int j,int count)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()  || grid[i][j]==0 || count>=time[i][j])
        {
            return;
        }
        time[i][j]=count;
        dfs(grid,time,i+1,j,count+1);
        dfs(grid,time,i-1,j,count+1);
        dfs(grid,time,i,j+1,count+1);
        dfs(grid,time,i,j-1,count+1);

    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<vector<int>> time(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    int count=0;
                    dfs(grid,time,i,j,count);
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    if(time[i][j]==INT_MAX)
                    {
                        return -1;
                    }
                    ans=max(ans,time[i][j]);
                    
                }
               
               
                
            }
        }
        return ans;
    }
};

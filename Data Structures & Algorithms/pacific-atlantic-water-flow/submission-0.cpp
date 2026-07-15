class Solution {
public:
    void dfs(vector<vector<int>> &heights,int i,int j,vector<vector<int>> &visited,int oi,int oj)
    {
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || visited[i][j] || (oi>=0 && oi<heights.size() && oj>=0 && oj < heights[0].size() && heights[i][j]< heights[oi][oj])  )
        {
            return;
        }
        visited[i][j]=1;
        dfs(heights,i+1,j,visited,i,j);
        dfs(heights,i-1,j,visited,i,j);
        dfs(heights,i,j+1,visited,i,j);
        dfs(heights,i,j-1,visited,i,j);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {

       vector<vector<int>> pacific(heights.size(),vector<int>(heights[0].size(),0));
       vector<vector<int>> atlantic(heights.size(),vector<int>(heights[0].size(),0)); 
       int r=heights.size();
       int c=heights[0].size();
       for(int i=0;i<r;i++)
       {
        dfs(heights,i,0,pacific,-1,-1);
        dfs(heights,i,c-1,atlantic,-1,-1);
       }
       for(int j=0;j<c;j++)
       {
        dfs(heights,0,j,pacific,-1,-1);
        dfs(heights,r-1,j,atlantic,-1,-1);
       }
       vector<vector<int>> ans;
       for(int i=0;i<r;i++)
       {
        for(int j=0;j<c;j++)
        {
            if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
        }
       }
    return ans;
    }
};

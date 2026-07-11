class Solution {
public:
    void dfs(vector<vector<int>> &adjlist,int i,vector<int> &visited)
    {
        
        visited[i]=1;
        for(int j=0;j<adjlist[i].size();j++)
        {
            if(!visited[adjlist[i][j]])
            {
                dfs(adjlist,adjlist[i][j],visited);
            }
        }
       
    }
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        int component=0;
        vector<int> visited(n);
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][1]].push_back(edges[i][0]);
            adjlist[edges[i][0]].push_back(edges[i][1]);

        }
        for(int i=0;i<adjlist.size();i++)
        {
            if(!visited[i])
            {
                dfs(adjlist,i,visited);
                component++;
            }
        }
        return component;

    }
};

class Solution {
public:
    bool dfs(vector<vector<int>> &adjlist,int i,vector<int> &visited,int parent)
    {
        visited[i]=1;
        
        for(int j=0;j<adjlist[i].size();j++)
        {
            if(!visited[adjlist[i][j]])
            {
                if(dfs(adjlist,adjlist[i][j],visited,i))
                {
                    return true;
                }
            } else if(adjlist[i][j]!=parent)
            {
                return true;
            }
           
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size()!=n-1)
        {
            return false;
        }
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);

        }
        vector<int> visited(n,0);
        for(int i=0;i<adjlist.size();i++)
        {
            if(!visited[i])
            {
                if(dfs(adjlist,i,visited,-1))
                {
                    return false;
                }
            }
        }
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            return false;
        }
    }
    return true;

    }
};

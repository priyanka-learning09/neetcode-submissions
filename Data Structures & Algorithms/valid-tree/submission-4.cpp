class Solution {
public:
    bool dfs(vector<vector<int>> &adjlist,vector<int> &visited,int i,int parent)
    {
        visited[i]=1;
        for(int neigh: adjlist[i])
        {
            if(!visited[neigh])
            {
                if(dfs(adjlist,visited,neigh,i))
                {
                    return true;
                }
            }else if(parent!=neigh)
            {
                return  true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        vector<int> visited(n,0);
    
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
           
        }
        
                if(dfs(adjlist,visited,0,-1))
                {
                    return false;
                }
            
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }

    return true;
    }
};

class Solution {
public:
    bool dfs(vector<vector<int>> &adjlist,vector<int> &visited,int i,vector<int>& path)
    {
        path[i]=1;
        visited[i]=1;
        for(int neigh: adjlist[i])
        {
            if(!visited[neigh])
            {
                if(dfs(adjlist,visited,neigh,path))
                {
                    return true;
                }
            }
            else if(visited[neigh] && path[neigh])
            {
                return true;
            }
        }
        path[i]=0;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adjlist(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<adjlist.size();i++)
        {
           if(!visited[i])
            {
                if(dfs(adjlist,visited,i,path))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

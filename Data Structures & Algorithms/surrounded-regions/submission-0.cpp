class Solution {
public:
    void dfs(vector<vector<char>> &board,int i,int j)
    {
        if(i<0 || i>=board.size()|| j<0 || j>=board[0].size() || board[i][j]=='X' || board[i][j]=='S')
        {
            return;
        }
        board[i][j]='S';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) 
    {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<board.size();i++)
        {
          dfs(board,i,0);
          dfs(board,i,c-1);
        }
        for(int j=0;j<c;j++)
        {
            dfs(board,0,j);
            dfs(board,r-1,j);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='S')
                {
                    board[i][j]='O';
                }
            }
        }
        
        
    }
};

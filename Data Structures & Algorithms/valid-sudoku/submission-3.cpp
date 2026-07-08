class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> boxes(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                int boardindex=(i/3)*3+(j/3);
                if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || boxes[boardindex].count(board[i][j]) )
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                boxes[boardindex].insert(board[i][j]);
            }
            }
        return true;
    }
};

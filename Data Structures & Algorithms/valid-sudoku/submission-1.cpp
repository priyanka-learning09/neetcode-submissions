class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> boxes(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                int boardindex=(i/3)*3+(j/3);
                if(rows[i].count(board[i][j]) ||
                cols[j].count(board[i][j]) ||
                boxes[boardindex].count(board[i][j]))
                {
                    return false;
                }
                else{
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[boardindex].insert(board[i][j]);

                }
            }
        }


        return true;
    }
};

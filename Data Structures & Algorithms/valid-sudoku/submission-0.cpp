class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        unordered_set<string> rows;
        unordered_set<string> cols;
        unordered_set<string> boxs;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                string num(1,board[i][j]);
                string rkey=num+"r"+to_string(i);
                string ckey=num+"c"+to_string(j);
                string bkey=num+"b"+to_string(i/3)+to_string(j/3);
                if(rows.count(rkey)|| cols.count(ckey)|| boxs.count(bkey))
                {
                    return false;
                }
                rows.insert(rkey);
                cols.insert(ckey);
                boxs.insert(bkey);            
            
            }
        }
        return true;

        
        
    }
};

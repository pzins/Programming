class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int count = 0;

        for(int r = 0; r < board.size(); ++r)
        {
            for(int c = 0; c < board.at(0).size(); ++c)
            {
                if(board[r][c] == 'X' || board[r][c] == 'W')
                {
                    if(board[r][c] == 'X') count++;
                    if(c < board.at(0).size()-1 && board[r][c+1] ==  'X') board[r][c+1] = 'W';
                    if(r < board.size()-1 && board[r+1][c] ==  'X') board[r+1][c] = 'W';
                }
            }
        }
        return count;
    }
};

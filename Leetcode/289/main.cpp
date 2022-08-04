class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int   COL     = board.size();
        const int   ROW     = board[0].size();
        const int   DEAD    = 2;
        const int   LIVE    = -2;
        
        int         count   = 0;
        
        
        for (int i = 0; i < COL; i++){
            for (int j = 0; j < ROW; j++){
                count = 0;
                
                if (i > 0 && j > 0 && board[i - 1][j - 1] >= 1)
                    count ++;
                if (i > 0 && board[i - 1][j] >= 1)
                    count ++;
                if (i > 0 && j < ROW - 1 && board[i - 1][j + 1] >= 1)
                    count ++;
                
                if (j > 0 && board[i][j - 1] >= 1)
                    count ++;
                if (j < ROW - 1 && board[i][j + 1] >= 1)
                    count ++;
                
                if (i < COL - 1 && j > 0 && board[i + 1][j - 1] >= 1)
                    count ++;
                if (i < COL - 1 && board[i + 1][j] >= 1)
                    count ++;
                if (i < COL - 1 && j < ROW - 1 && board[i + 1][j + 1] >= 1)
                    count ++;
                
                if (board[i][j] == 1 && (count < 2 || count > 3))
                    board[i][j] = DEAD;
                if (board[i][j] == 0 && count == 3)
                    board[i][j] = LIVE;
            }
        }
        for (int i = 0; i < COL; i++){
            for (int j = 0; j < ROW; j++){
                if (board[i][j] == DEAD) 
                    board[i][j] = 0;
                if (board[i][j] == LIVE)
                    board[i][j] = 1;
            }
        }
    }
};

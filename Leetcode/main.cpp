class Solution {
public:
    double board[26][26][101];
    double knightProbability(int n, int k, int row, int column) {
        return dp(n, k, row, column);
    }
    double dp(int n, int k, int row, int col){
        if (row < 0 || col < 0 || row >= n || col >= n )
            return 0;
        
        if (k == 0)
            return 1;
        
        if (board[row][col][k])
            return board[row][col][k];
        
        double result = \
            dp(n, k - 1, row - 2, col - 1) + dp(n, k - 1, row - 2, col + 1) + \
            dp(n, k - 1, row - 1, col - 2) + dp(n, k - 1, row - 1, col + 2) + \
            dp(n, k - 1, row + 1, col - 2) + dp(n, k - 1, row + 1, col + 2) + \
            dp(n, k - 1, row + 2, col - 1) + dp(n, k - 1, row + 2, col + 1);
        result /= 8;
        return board[row][col][k] = result;
    }
};

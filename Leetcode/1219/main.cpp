class Solution {
public:
    int dfs(vector<vector<int>> & grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0)
            return 0;
        grid[i][j] = -grid[i][j];
        int m = max({dfs(grid, i + 1, j), dfs(grid, i, j + 1), dfs(grid, i - 1, j), dfs(grid, i, j - 1)});
        grid[i][j] = -grid[i][j];
        return grid[i][j] + m;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                result = max(result, dfs(grid, i, j));
            }
        }
        
        return result;
    }
};

	class Solution {
public:
    vector<vector<int>> dp;
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        dp = vector<vector<int>>(k + 1, vector<int>(nums.size(), -1));
        return dfs(nums, k, 0);
    }
    
    int dfs(vector<int> &nums, int k, int position){
        if (position >= nums.size()){
            return 0;
        }
        
        if (dp[k][position] != -1)
            return dp[k][position];
        
        int maxValue = 0;
        int total = 0;
        int sum; 
        int result = INT_MAX;
        
        if (k == 0){
            for (int i = position; i < nums.size(); i++){
                maxValue = max(maxValue, nums[i]);
                total += nums[i];
            }
            // 최대 값 * (남은 요소 개수) - 남은요소 합
            return maxValue * (nums.size() - position) - total;

        }
    
        // position 을 이동해 가면서 최적값 찾기
        for (int i = position; i < nums.size(); i++){
            maxValue = max(maxValue, nums[i]);
            total += nums[i];
            sum = maxValue * (i - position + 1) - total;
            result = min(result, sum + dfs(nums, k - 1, i + 1));
        }
            
        dp[k][position] = result;
        return result;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int index   = nums.size() - 1;
        int current = 0;
        return dp(nums, target, index, current);
    }
    
    int dp(vector<int>& nums, int& target, int index, int current){
        if (index < 0 && current == target)
            return 1;
        else if (index < 0)
            return 0;
        
        int plus    = dp(nums, target, index - 1, current + nums[index]);
        int minus   = dp(nums, target, index - 1, current - nums[index]);
        
        return plus + minus;
    }
};	

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long maxOdd = 0;
        long maxEven = 0;
        long temp = 0;
        
        maxOdd = nums[0];
        
        for (int i = 0; i < nums.size(); i ++){
            temp = maxOdd;
            maxOdd = max(maxOdd, maxEven + nums[i]);
            maxEven = max(maxEven, temp - nums[i]);
        }
        
        return maxOdd;
    }
};

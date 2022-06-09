class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long result = 0;
        long long front = 0;
        long long back = 0;
        
        // why cat't use std:accumulate?
        for (auto i : nums)
            back += i;
        
        for (int i = 0; i < nums.size() - 1; i++){
            front += nums[i];
            back -= nums[i];
            
            if (front >= back)
                result ++;
        }
        
        return result;
    }
};

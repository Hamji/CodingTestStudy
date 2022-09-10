class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        long left    = 0;
        long right   = 0;
        long result  = 0;
        long total   = 0;
        long leng    = nums.size();
        
        while (right < leng){
            total += nums[right];           
            while (nums[right] * (right - left + 1) - total > k){
                total -= nums[left];
                left++;
            }
            
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};



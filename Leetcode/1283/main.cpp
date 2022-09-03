class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int     left    = 1;
        int     right   = 1000001;
        int     result  = 0;
        int     mid     = 0;
        long    sum    = 0;
        
        while(left <= right){
            mid = (left + right) / 2;
            sum = 0;
            for (auto &n : nums){
                n % mid == 0 ? sum += (n / mid) : sum += (n / mid) + 1;
            }
            if (sum > threshold){
                left = mid + 1;
            }else{
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};

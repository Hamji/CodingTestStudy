class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.insert(nums.end(), 0);
        const int n = nums.size();
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0 || nums[i] >= n)
                nums[i] = 0;
        }
        
        //print(nums);
        
        for (int i = 0; i < nums.size(); i++){
            //int index = nums[i] % nums.size();
            int index = nums[i] % 5000002;
            nums[index] += 5000002;
        }
        
        //print(nums);
        
        for (int i = 1; i < n; i++){
            if (nums[i] / 5000002 == 0)
                return i;
        }
        return nums.size();
    }
    
    
    void print(vector<int>& nums){
        for (int i= 0; i < nums.size(); i++){
            std::cout <<  nums[i] << ' ';
        }
        std::cout << std::endl;
    }
};

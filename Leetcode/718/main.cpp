class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int matrix[1001][1001]  = {0};
        int result              = 0;
        
        
        for(int i = 0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++){
                if (nums1[i] == nums2[j]){
                    matrix[i + 1][j + 1] = matrix[i][j] + 1;
                    result = max(result, matrix[i + 1][j + 1]);
                }
            }
        }
        
        return result;
    }
};

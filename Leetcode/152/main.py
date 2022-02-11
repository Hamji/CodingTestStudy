# https://leetcode.com/problems/maximum-product-subarray/

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        #nums.sort()
        result = nums[0]
        current = mini = nums[0]

        for i in nums[1:]:
            t_current = max(i, i * current, i * mini)
            t_mini = min(i, i * current, i * mini)
            current = t_current
            mini = t_mini

            result = max(result, current )

        return result

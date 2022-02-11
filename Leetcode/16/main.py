class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = 9999
        leng = len(nums) - 1
        
        for i in range(len(nums) - 2):
            left = i + 1
            right = leng
            while left != right:
                temp = nums[i] + nums[left] + nums[right]
                if temp == target:
                    return target
                elif temp > target:
                    right -= 1
                else:
                    left += 1
                if abs(target - temp) <= abs(target - result):
                    result = temp

                #print("temp" + str(temp))

        return result
        

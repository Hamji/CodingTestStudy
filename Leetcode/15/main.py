class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()

        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            
            # 이전에 중복된 조합 막기 위함
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # 양수 나온다면 더이상 더해서 0이 안된다..
            if nums[i] > 0:
                break
            
            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum > 0:
                    right -= 1
                elif sum < 0:
                    left += 1
                else:
                    results.append([nums[i], nums[left], nums[right]])

                    # 중복 막기
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1
    
        return results

//https://leetcode.com/problems/house-robber/
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func rob(nums []int) int {
    if len(nums) == 0{
        return 0
    }else if len(nums) == 1{
        return nums[0]
    }
    
    // arr [1, 2, 3, 1] 
    // dp  [0, 0, 0, 0]
    // dp  [1, 2, 0, 0]
    // dp  [1, 2, 4, 0] 2 < 1 + 3
    // dp  [1, 2, 4, 4] 4 > 2 + 1 
    
    // 해당 인덱스까지 합중에 큰거
    var dp = make([]int, len(nums))
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    
    // 현재 dp 인덱스 이전 값의 합 vs 현재값 + 전전값 비교
    for i := 2; i < len(nums); i++{
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
    }
    
    return dp[len(nums) - 1]
}

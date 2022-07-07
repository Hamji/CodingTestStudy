class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long dp[500000] = {};
        for (int i = questions.size() - 1; i >= 0; i--){
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        }
        return dp[0];
    }
};

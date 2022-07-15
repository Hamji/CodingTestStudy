class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int                         result = 0;
        int                         maxim = 0;
        unordered_map<char, int>    count;
        
        for (int i = 0; i < answerKey.size(); i++){
            count[answerKey[i]]++;
            maxim = max(maxim, count[answerKey[i]]);
            if (result - maxim < k)
                result++;
            else
                count[answerKey[i - result]]--;
        }
        
        return result;        
    }
};

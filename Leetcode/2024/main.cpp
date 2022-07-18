class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int head = 0;
        int tail = 0;
        int countT = 0;
        int countF = 0;
        int size = answerKey.size();
        int result = 0;
        
        while (head < size){
            if (answerKey[head] == 'T')
                countT++;
            else
                countF++;
            int mini = min(countT, countF);
            
            if (mini <= k)
                result = max(result, head - tail + 1);
            else{
                while(mini > k){
                    if (answerKey[tail] == 'T')
                        countT--;
                    else
                        countF--;
                    mini = min(countT, countF);
                    tail++;
                }
            }
            head ++;
        }
        
        return result;
    }
};

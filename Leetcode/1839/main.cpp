class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int         result  = 0;
        int         count   = 1;
        int         comple  = 1;
        
        
        for (int i = 1; i < word.size() ; i++){
            if (word[i - 1] <= word[i]){
                count++;
                if (word[i- 1] < word[i])
                    comple++;
            }else{
                count = 1;
                comple = 1;
            }
            
            if (comple == 5)
                result = max(result, count);
        }
        return result;
    }
};

class Solution {
public:
    int count[26] = {0};
    
    int numTilePossibilities(string tiles) {
        for (const auto &t : tiles){
            count[t - 'A']++;
        }
        
        int result = 0;
        recursive(result);
        return result;
    }
    
    void recursive(int &result){
        for (int i = 0; i < 26; i ++){
            if (count[i]){
                count[i]--;
                result ++;
                recursive(result);
                count[i]++;
            }
        }
    }
};

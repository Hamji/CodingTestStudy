class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> map;
        int result = 0;
        
        // 같은 row 구조인지 찾는다
        for (auto& c : matrix){
            string st = "";
            int top = c[0];
            
            for (auto& i : c){
                // Same
                if (i == top)
                    st += "S";
                // Differnt
                else
                    st += "D";
            }
            map[st]++;
        }
        
        // 가장 많은 row 구조라면 그게 아마 최대일 것이다.
        for (auto &[key, val] : map)
            result = max(result, val);
        return result;
    }
};


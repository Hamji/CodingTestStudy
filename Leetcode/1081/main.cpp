class Solution {
public:
    string smallestSubsequence(string s) {
        string result = "";
        
        int count[26] = {0};
        bool visited[26] = {false};

        for (char c : s) 
            ++count[c - 'a'];
        
        for (char c : s){
            count[c - 'a'] --;
            //해당 문자열 방문했는지 체크
            if (visited[c - 'a']){
                continue;
            }else{
                visited[c - 'a'] = true;
            }

            
            // 한번 씩은 들어가야하고, 사전순으로
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0){
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
        }
        return result;
    }
};

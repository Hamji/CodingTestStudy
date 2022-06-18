class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        char gene[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> dict(bank.begin(), bank.end());        
        int result = 0;
        queue<string> q;
        int qlen = 0;
        char c = 0;
        
        q.push(start);
        
        
        while (q.empty() != true){
            // queue가 가변적이라 개수 체크를 위해
            qlen = q.size();
            
            for (int i = 0; i < qlen; i++){
                string current = q.front();
                q.pop();
                dict.erase(current);
                if (current == end)
                    return result;

                for (int j = 0; j < 8; j++){
                    c = current[j];
                    for (int k = 0; k < 4; k++){
                        current[j] = gene[k];
                        // 있으면 큐에 삽입
                        if ( dict.find(current) != dict.end())
                            q.push(current);
                    }
                    current[j] = c;
                }
            }
            result++;
        }
        
        return -1;
    }
};

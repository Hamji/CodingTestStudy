class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>     dislist(n + 1);
        vector<int>             combi(n + 1, 0);
        vector<bool>            visit(n + 1, 0);
        queue<int>              q;
        
        
        for (auto &d : dislikes){
            int fir = d[0];
            int sec = d[1];
            dislist[fir].push_back(sec);
            dislist[sec].push_back(fir);
        }
        
        for (int i = 1; i <= n; i++){
            if (!visit[i]){
                combi[i] = 1;
                q.push(i);                
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    if (visit[node])
                        continue;
                    
                    visit[node] = true;
                    
                    for (auto v : dislist[node]){
                        // 싫어하는데 같은 진영이면 XX 
                        if (combi[v] == combi[node])
                            return false;
                        
                        if (combi[node] == 1)
                            combi[v] = 2;
                        else
                            combi[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};

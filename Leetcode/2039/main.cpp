class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int                 n       = patience.size();
        vector<int>         dis(n, INT_MAX);
        vector<vector<int>> graph(n);
        queue<int>          q;
        

        vector<bool>        visit(n, false);
        int                 d       = 0;
        int                 result  = 0;
        
        for (auto &e : edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        q.push(0);
        visit[0] = true;
        
        
        while (!q.empty()){
            for (int i = q.size(); i > 0; i--){
                int u = q.front();
                q.pop();
                dis[u] = d;
                for (auto v : graph[u]){
                    if (visit[v]) continue;
                    q.push(v);
                    visit[v] = true;
                }
            }
            d++;
        }
        
        for (int i = 1; i < n; i++){
            int receiveTime = dis[i] * 2;
            int resend      = (receiveTime - 1) / patience[i];
            result = max(result, receiveTime + resend * patience[i]);
        }
        
        return result + 1;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
		vector<vector<int>> group(n);
        long long result = 0;
        for (auto& e : edges){
            group[e[0]].push_back(e[1]);
            group[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> sizes;
        
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                int size = 0;
                dfs(i, group, visited, size);
                sizes.push_back(size);                
            }

        }
        
        for (int i : sizes){
			n = n - i;
            result += (long long)i * (long long)n;
        }
        
        return result;
    }

	void dfs(int i, vector<vector<int>>& group, vector<bool>& visited, int& size){
        visited[i] = 1;
        size++;
        for (int j : group[i]){
            if (!visited[j])
                dfs(j, group, visited, size);
        }
    }
};

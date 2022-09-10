class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem(n,vector<int>(n));
        return mujisung(0,n-1, s,mem); 
    }
    
    int mujisung(int l, int r, string &s, vector<vector<int>>& memory){
        if (l == r) 
            return 1;
        if (l > r)  
            return 0;
        if (memory[l][r]) 
            return memory[l][r];
        
        return memory[l][r] = s[l] == s[r] ? 2 + mujisung(l + 1, r - 1, s, memory) : max(mujisung(l + 1, r, s, memory), mujisung(l, r -1, s, memory));
    }

};



class RangeFreqQuery {   
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            this->queryVector[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        return upper_bound(begin(queryVector[value]), end(queryVector[value]), right) -
            lower_bound(begin(queryVector[value]), end(queryVector[value]), left); 
    }
private:
    unordered_map<int, vector<int>> queryVector;
};

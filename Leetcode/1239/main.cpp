class Solution {
public:
    vector<bitset<26>> bits;    
    
    int maxLength(vector<string>& arr) {

        for (auto a : arr){
            bitset<26> temp;
            for (char c : a){
                temp.set( c - 'a');
            }
            if (temp.count() == a.size()) bits.push_back(temp);
        }
        
        return recursive(bitset<26>(), 0);
    }
    
    int recursive(bitset<26> bs, int index){
        int result = bs.count();
        
        for (int i = index; i < bits.size(); i++){
            // 다르면
            if (!(bits[i] & bs).any()) 
                result = max(result, recursive(bs | bits[i], i + 1));
        }
        return result;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        
        map<int, int>   mp;
        int             now = 0;
        
        for (auto &h : hand){
            mp[h]++;
        }
        
        while (mp.size() != 0){
            now = mp.begin()->first;
            for (int i = 0; i < groupSize; i++){
                if (mp[now + i] == 0)
                    return false;
                else if (--mp[now + i] < 1){
                    mp.erase(now + i);
                }
            }
        }
        
        return true;
    }
};

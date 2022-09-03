class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count[5]    = {0}; 
        int frogs       = 0;
        int result      = 0;
        int index;
        
        for (auto c : croakOfFrogs){
            index = string("croak").find(c);
            count[index]++;
            
            if (index == 0)
                result = max(result, ++frogs);
            else if (--count[index - 1] < 0)
                return -1;
            else if (index == 4)
                --frogs;
        }
        
        return frogs == 0 ? result : -1;
    }
};

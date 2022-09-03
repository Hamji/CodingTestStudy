class Solution {
public:
    
    int func(char c, string &st){
        int result = 0;
        
        for (char s : st){
            if (s != c)
                result++;
            c = c =='0' ? '1' : '0';
        }
        
        return result / 2;
    }
    
    int minSwaps(string s) {
        int num0 = count(begin(s), end(s), '0');
        int num1 = s.size() - num0;
        
        if (num0 - num1 < -1 || num1 - num0 < -1)
            return -1;

        if (num0 > num1)
            return func('0', s);
        else if (num0 < num1)
            return func('1', s);
        else
            return min(func('1', s), func('0', s));
        
    }
};

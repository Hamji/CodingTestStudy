//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        int result = 0;
        int digit = 0;
        if (x == -2147483648 || x == 0 )
            return 0;
        if (x < 0)
        {
            x = -x;
            sign = -1;
        }
        else
            sign = 1;
        
        while (x != 0)
        {
            digit++;
            
            if (digit == 10)
            {
                if (sign == -1)
                {
                    if (result > 214748364)
                        if (x % 10 > 8)
                            return 0;
                }
                else
                {
                    if (result > 214748364)
                        if (x % 10 > 7)
                            return 0;
                }
            }
            
            result *= 10;
            result += x % 10;
            x = x / 10;
        }
        
        
        return sign * result;
    }
};

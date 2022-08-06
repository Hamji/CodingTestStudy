class StockSpanner {
public:
    // first  : price 
    // second : count
    stack<pair<int, int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;
        
        while (!s.empty() && s.top().first <= price){
            result += s.top().second;
            s.pop();
        }
        s.push({price, result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

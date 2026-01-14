class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int day = 1;
        while(!s.empty() && s.top().first <= price) {
            day += s.top().second;
            s.pop();
        }
        s.push({price, day});
        return day;
    }
};
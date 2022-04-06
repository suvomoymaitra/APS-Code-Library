// https://leetcode.com/problems/stock-price-fluctuation/
// Concept used : Heap or priority queue
class StockPrice {
public:
    multiset <int> ms;
    map<int,int> m;
    int latest_ts;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp>latest_ts){
            latest_ts = timestamp;
        }
        int tmp = m[timestamp];
        m[timestamp] = price;
        
        auto itr = ms.find(tmp);
        if(itr!=ms.end()) ms.erase(itr);
        
        ms.insert(price);
    }
    
    int current() {
        return m[latest_ts];
    }
    
    int maximum() {
        int ans = *ms.rbegin();
        return ans;
    }
    
    int minimum() {
        int ans = *ms.begin();
        return ans;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

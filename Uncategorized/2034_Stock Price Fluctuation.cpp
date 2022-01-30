class StockPrice {
private:
    unordered_map<int, int> toPrice;
    multiset<int> prices;
    int latest = 0;

public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (toPrice.count(timestamp)) {
            prices.erase(prices.find(toPrice[timestamp]));   // erase the first-found previous price.
        }
        prices.insert(price);
        toPrice[timestamp] = price;
        latest = max(latest, timestamp);
    }
    
    int current() {
        return toPrice[latest];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
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
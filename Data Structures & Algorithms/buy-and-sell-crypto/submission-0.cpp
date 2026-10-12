class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int l = 0; int r = 1; 
    
        int maxProfit = 0;
        while (l < prices.size() && r < prices.size()) {
            int buyPrice = prices[l]; int sellPrice = prices[r];

            if (sellPrice < buyPrice) {
                l = r;
            }
            
            maxProfit = max(maxProfit, sellPrice-buyPrice);
            r++;
        }
        
        return maxProfit;
    }
};

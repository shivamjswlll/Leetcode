class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int i = 0 ;i< prices.size();i++){
            int onedayprofit = prices[i] - buy;
            profit = max(profit,onedayprofit);
            buy = min(prices[i],buy);
        }

        return profit;
    }
};
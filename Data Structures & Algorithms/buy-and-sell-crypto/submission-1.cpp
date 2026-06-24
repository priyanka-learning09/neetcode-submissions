class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        int minbuy=INT_MAX;
        for(int num:prices)
        {
            minbuy=min(minbuy,num);
            profit=max(profit,num-minbuy);
        }
        return profit;
    }
};

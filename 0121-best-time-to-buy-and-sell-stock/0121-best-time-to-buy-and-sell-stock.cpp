class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for(auto i:prices){
            minprice = min(minprice ,i);
            maxprofit  =max(maxprofit,i-minprice);
        }
        return maxprofit;
    }
        
    };
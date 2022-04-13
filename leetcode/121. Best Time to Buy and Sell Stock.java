



class Solution {
       
    public int maxProfit(int[] prices){
        if(prices.length < 2) return 0;
        int min = Integer.MAX_VALUE;
        int res = 0;
        for(int i = 0; i < prices.length; ++i){
            min = Math.min(min, prices[i]);
            res = Math.max(res, prices[i] - min);
        }
        return res;
    }
    
    // --------- sliding window (not neccesary) -----------
    public int maxProfit_1(int[] prices) {
        if(prices.length < 2) return 0;
        int l = 0, r = 1;
        int res = 0;
        while(r < prices.length){
            if(prices[l] >= prices[r]){
                l = r;
            }
            else{
                res = Math.max(res, prices[r] - prices[l]); 
            }
            ++r;
        }
        return res;
    }
}
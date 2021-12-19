class Solution {
    public int maxProfit(int[] prices) {
      int maxpro=0;
      int min=prices[0];
      for(int i=0;i<prices.length;i++){
          min=Math.min(prices[i],min);
          maxpro=Math.max(prices[i]-min,maxpro);
      }  
      return maxpro;
    }
}

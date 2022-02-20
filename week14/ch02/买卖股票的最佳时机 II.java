class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        if(n==1)
        return 0;
        int i,nums=0,flag;
        for(i=1;i<n;i=flag){
            flag=i+1;
            if(prices[i]>prices[i-1]){
            nums+=prices[i]-prices[i-1];
            }
        }
        return nums;
    }
}

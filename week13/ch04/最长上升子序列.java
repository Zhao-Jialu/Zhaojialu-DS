class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp=new int[n];
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int max=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j])
                max=Math.max(max,dp[j]);
            }
            dp[i]=max+1;
        }
        int result=0;
        for(int i=0;i<dp.length;i++){
            if(dp[i]>result)
            result=dp[i];
        }
        return result;
    }
}

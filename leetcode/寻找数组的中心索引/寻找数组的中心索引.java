class Solution {
    public int pivotIndex(int[] nums) {
        int length = nums.length;
        int sum=0,sum1=0;
        for(int i=0;i<length;i++){
           sum+=nums[i]; 
        }
        if(sum-nums[0]==0)
        return 0;
        for(int i=1;i<length;i++){
            sum1 +=nums[i-1];
            int end = sum-sum1-nums[i];
            if(sum1==end)
            return i; 
        }
        return -1;
    }
}

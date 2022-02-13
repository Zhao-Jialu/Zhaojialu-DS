class Solution {
    public boolean canJump(int[] nums) {
       int length=nums.length;
       int n=1;
       for(int i=length-2;i>=0;i--){
           if(nums[i]>=n)
           n=1;
           else
           n++;
           
           if(i==0&&n>1)
           return false;
       }
       return true;
    }
}

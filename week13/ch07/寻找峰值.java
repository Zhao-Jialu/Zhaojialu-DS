class Solution {
    public int findPeakElement(int[] nums) {
        int result=-1;
        if(nums.length==1)
        return 0;
        for(int i=0;i<nums.length;i++){
            if(i==0&&nums[i]>nums[i+1])
            return i;
            if(i==nums.length-1&&nums[i]>nums[i-1])
            return i;
            if(nums[i]>nums[i+1]&&nums[i]>nums[i-1])
            return i;
        }
        return result;
    }
}

class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target)
            return i;
        }
        for(int j=0;j<nums.length;j++){
            if(j==nums.length-1&&target>nums[j])
            return j+1;
            if(target>nums[j]&&target<nums[j+1])
            return j+1;
        }
        return 0;
    }
}

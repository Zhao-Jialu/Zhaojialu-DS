class Solution {
    public void sortColors(int[] nums) {
        int left=0, right=nums.length-1;   //left代表红色，right代表蓝色
        for(int i=0; i<=right; i++){
            if(nums[i] == 0){
                swap(nums, left, i);
                left++;
            }
            if(nums[i] == 2){
                swap(nums, i, right);
                right--;
                i--;                     //防止漏算
            }
        }
    }
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

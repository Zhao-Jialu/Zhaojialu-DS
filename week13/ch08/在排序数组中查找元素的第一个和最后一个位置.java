class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] str={-1,-1};
        int i=0,j=nums.length-1;
        while(i<=j){
            while(i<=j&&nums[i]!=target){
            i++;
            }
            while(j>=i&&nums[j]!=target){
            j--;
            }
            if(i<=j)
            return new int[]{i,j};
        }
        return str;
    }
}

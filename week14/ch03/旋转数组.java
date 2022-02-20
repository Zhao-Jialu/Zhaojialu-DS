class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length,i;
        int[] a=new int[n];
        for(i=0;i<n;i++){
            a[i]=nums[i];
        }
        for(i=0;i<n;i++){
            nums[(i+k)%n]=a[i];
        }
    }
}

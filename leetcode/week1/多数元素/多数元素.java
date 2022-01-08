class Solution {
    public int majorityElement(int[] nums) {
        int max=0,index=1;
        Arrays.sort(nums);
        int flag=nums[0];
        int s=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=flag){
                flag=nums[i];
                if(max<index){
                    max=index;
                    s=nums[i-1];
                }
                index=1;
            }
            index++;
        }
        if(max<index){
            s=nums[nums.length-1];
        }
        return s;

    }
}

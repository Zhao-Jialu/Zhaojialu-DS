class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> str = new ArrayList<List<Integer>>();
        int length = nums.length;
        if(length<3)
        return str;
        
        for(int i=0;i<length;i++){
            for(int j=1;j<length;j++){
                List<Integer> rte = new ArrayList<>();
                for(int k=2;k<length;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        rte.add(i);
                        rte.add(j);
                        rte.add(k);
                        str.add(rte);
                    }
                }
            }
            int slow=0,fast=1;
            int index=str.size();
            while(slow<index){
                if(slow==fast)str.remove(fast);
                else
                fast++;
                if(fast==str.size()){
                    slow++;
                    fast=slow+1;
                }
                index=str.size();
            }
        }
        return str;
    }
}

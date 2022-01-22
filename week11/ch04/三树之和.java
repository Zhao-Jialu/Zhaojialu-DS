class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for(int first=0;first<n;first++){
            if(first>0&&nums[first]==nums[first-1])
            continue;
            int third = n-1;
            int target =-nums[first];
            for(int second=first+1;second<n;second++){
                if(second>first+1&&nums[second]==nums[second-1])
                continue;
                while(second<third&&nums[second]+nums[third]>target){
                    third--;
                }
                if(third==second)
                break;
                if(nums[second]+nums[third]==target){
                    List<Integer> ret = new ArrayList<>();
                    ret.add(nums[first]);
                    ret.add(nums[second]);
                    ret.add(nums[third]);
                    ans.add(ret);
                }
            }
        }
        return ans;
    }
}

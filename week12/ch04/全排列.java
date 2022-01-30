class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> str=new ArrayList<List<Integer>>();
        backtrack(str,new ArrayList<>(),nums);
        return str;
    }
    public void backtrack(List<List<Integer>> str,List<Integer> temp,int[] nums){
        if(temp.size()==nums.length){
            str.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(temp.contains(nums[i]))
            continue;
            temp.add(nums[i]);
            backtrack(str,temp,nums);
            temp.remove(temp.size()-1);
        }
    }
}

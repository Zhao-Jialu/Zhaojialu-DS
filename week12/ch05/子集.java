class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> str=new ArrayList<List<Integer>>();
        backtrack(str,new ArrayList<>(),nums,0);
        return str;
    }
    public void backtrack(List<List<Integer>> str,List<Integer> temp,int[] nums,int index){
            str.add(new ArrayList<>(temp));
        for(int i=index;i<nums.length;i++){
            temp.add(nums[i]);
            backtrack(str,temp,nums,i+1);
            temp.remove(temp.size()-1);
        }
        
    }
}

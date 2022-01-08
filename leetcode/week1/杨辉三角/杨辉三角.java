class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> str=new ArrayList<List<Integer>>();
        for(int i=0;i<numRows;i++){
            List<Integer> ret=new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                ret.add(1);
                }
                else{
                    ret.add(str.get(i-1).get(j-1)+str.get(i-1).get(j));
                }
            }
            str.add(ret);
        }
        return str;
    }
}

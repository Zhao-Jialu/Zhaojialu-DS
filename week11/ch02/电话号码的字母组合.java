class Solution {
    public List<String> letterCombinations(String digits) {
        //定义一个返回的结果集
        List<String> res = new ArrayList<>();
        //如果字符串为空，直接返回
        if(digits.length() == 0){
            return res;
        }
        //定义一个集合表示字符串的所有可能
        Map<Character,String> map = new HashMap<>(){{
            put('2',"abc");
            put('3',"def");
            put('4',"ghi");
            put('5',"jkl");
            put('6',"mno");
            put('7',"pqrs");
            put('8',"tuv");
            put('9',"wxyz");
        }};
        //定义一个存储路径的可变字符的变量
        StringBuilder path = new StringBuilder();
        //递归
        dfs(path,map,digits,0,res);
        return res;
    }
    public void dfs(StringBuilder path,Map<Character,String> map, String digits,int dept,List<String> res){
        //当递归到底层的时候，将路径上的参数加入结果集中
        if(dept == digits.length()){
            res.add(path.toString());
        }else{
            //定义一个存储字符串的数字
            char digit = digits.charAt(dept);
            //定义一个存储数字对应的所有可能字符串
            String str = map.get(digit);
            //定义一个表示字符串长度
            int len = str.length();
            //遍历字符串
            for(int i = 0; i< len; i++){
                //将字符添加进路径结果中
                path.append(str.charAt(i));
                //递归
                dfs(path, map,digits,dept+1,res);
                //剪枝
                path.deleteCharAt(dept);
            }
        }

    }
}

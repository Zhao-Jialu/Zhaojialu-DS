class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs==null||strs.length==0)
        return new ArrayList<>();
         Map<String, List<String>> map = new HashMap<>();
        for(int i=0;i<strs.length;i++){
            char[] c = strs[i].toCharArray();
            Arrays.sort(c);
            String keyStr=String.valueOf(c);
             if (!map.containsKey(keyStr))
            map.put(keyStr, new ArrayList<>());
            map.get(keyStr).add(strs[i]);

        }
        return new ArrayList<>(map.values());
    }
}

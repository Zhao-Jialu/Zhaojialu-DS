class Solution {
    public int repeatedStringMatch(String a, String b) {
        if(b.length()==0)
        return 0;
        StringBuffer sb = new StringBuffer();
        int ans=0;
        int max=a.length()+b.length();
        while(sb.length()<max){
            sb.append(a);
            ans++;
            if(sb.toString().indexOf(b)!=-1)
            return ans;
        }
        return -1;
    }
}

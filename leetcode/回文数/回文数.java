class Solution {
    public boolean isPalindrome(int x) {
        if(x==0)
        return true;
        if(x<0)
        return false;
        int tmp=0;
        int y=0;
        int x1=x;
        while(x!=0){
        tmp=x%10;
        x=x/10;
        y=y*10+tmp;
        }
        if(x1!=y)
        return false;
        else
        return true;
    }
}

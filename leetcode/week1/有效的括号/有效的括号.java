class Solution {
    public boolean isValid(String s) {
        char[] str=s.toCharArray();
        LinkedList<Character> stack = new LinkedList<>();
        for(int i=0;i<str.length;i++){
            if(str[i]=='('||str[i]=='['||str[i]=='{')
            stack.push(str[i]);
            else if(str[i]==')'){
                if(stack.size()==0)
                return false;
                
                char a = stack.pop();
                if(a!='(')
                return false;
            }
             else if(str[i]==']'){
                if(stack.size()==0)
                return false;
                
                char b = stack.pop();
                if(b!='[')
                return false;
            }
             else if(str[i]=='}'){
                if(stack.size()==0)
                return false;
                
                char c = stack.pop();
                if(c!='{')
                return false;
            }
            
        }
        if(stack.size()!=0)
        return false;

        return true;
    }
}

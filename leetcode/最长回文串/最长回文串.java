class Solution {
            public int longestPalindrome(String s) {
                int[] arr = new int[58];
                for(int i=0;i<s.length();i++){
                    arr[s.charAt(i)-'A']++;
                }
                int max=0;
                int flag=0;
                for(int j=0;j<arr.length;j++){
                    if(arr[j]%2==0){
                        max+=arr[j];
                    }else{
                        max=max+arr[j]-1;
                        flag++;
                    }
                }
                if(flag!=0)
                    max++;
                return max;
            }
        }

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    if(n==0)
    return;
    int a=0;
    int b=0;
    int[] nums3=new int[m];
    for(int i=0;i<m;i++){
        nums3[i]=nums1[i];
    }
    int i=0;
    while(a<n&&b<m){
        if(nums2[a]<=nums3[b]){
            nums1[i++]=nums2[a];
            a++;
        }else if(nums2[a]>nums3[b]){
            nums1[i++]=nums3[b];
            b++;
        }
    }
    while(a==n&&b<m){
        nums1[i++]=nums3[b];
        b++;
    }
    while(b==m&&a<n){
      nums1[i++]=nums2[a];
        a++;  
    }
    }
}

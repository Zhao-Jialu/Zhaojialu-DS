class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int i=0;
        int j=1;
        int index=1;
        while(j<intervals.length){
            if(intervals[i][1]>=intervals[j][0]){
                if(intervals[i][1]<=intervals[j][1])
                intervals[i][1]=intervals[j][1];
                intervals[j][0]=-1;
                j++;
            }else{
                index++;
                i=j;
                j++;
            }
        }
        int[][] arr = new int[index][2];
        int n=0;
        for(int m=0;m<intervals.length;m++){
            if(intervals[m][0]!=-1)
            arr[n++]=intervals[m];
        }
        return arr;
    }
}

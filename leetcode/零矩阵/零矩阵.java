class Solution {
    public void setZeroes(int[][] matrix) {
        int M=matrix.length;
        int N=matrix[0].length;
        int[] row=new int[M*N];
        int[] col=new int[N*M];
        int index1=0;
        int index2=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j]==0){
                    row[index1++]=i;
                    col[index2++]=j;
                }
            }
        }
        for(int i=0;i<index1;i++){
            int a = row[i];
           for(int j=0;j<N;j++){
                matrix[a][j]=0;
            }
        }
        for(int j=0;j<index2;j++){
            int b = col[j];
            for(int i=0;i<M;i++){
                matrix[i][b]=0;
            }
        }
    }
}

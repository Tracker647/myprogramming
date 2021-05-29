package Chapter1;

public class Practice1115 {
    public static void main(String[] args) {
        int[] a = {2,6,3,4,3,6,3};
        int[] ans = histogram(a,a.length);
        for(int i:ans)
            System.out.printf("%d ",i);
    }
    public static int[] histogram(int[] a,int M){
        int[] ans = new int[M];
        int len = (a.length > M)?M:a.length - 1;
        for(int i = 0; i < len; i ++ ){
            ans[a[i]]++;
        }
        return ans;
    }
}

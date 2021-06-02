package Chapter1;

public class Practice1124 {
    public static void main(String[] args) {
        Euclid( Integer.parseInt(args[0]) , Integer.parseInt(args[1]) );

    }
    public static void Euclid (int p,int q){
        System.out.printf("gcd is %d",  gcd(p,q));
    }
    public static int gcd(int p ,int q)
    {
        System.out.printf(" p: %d , q: %d \n", p , q);
        if(q == 0) return p;
        int r = p % q;
        return gcd(q,r);
    }

}

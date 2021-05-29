public class F{
    int i;
    static String s;
    void imethod(){
        System.out.println(i);
        System.out.println(s);
        imethod();

    }
    static void smethod(){
        imethod();
        System.out.println(i);
        System.out.println(s);
    
    }
    public static void main(String[] args){
        F f = new F();
        System.out.println(f.i);
        imethod();
        f.imethod();
        smethod();
    }
}
public class Voidreturn {
    public static void main(String[] args) {
        xMethod(2, 3);
    }

    public static void xMethod(double x, double y) {
        System.out.println(x + y);
        return x + y;
    }
}

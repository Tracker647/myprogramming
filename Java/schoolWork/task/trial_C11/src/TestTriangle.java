import java.util.Scanner;

public class TestTriangle {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the side1,side2,side3,color and fill Status of Triangle:");
        double side1 = input.nextDouble();
        double side2 = input.nextDouble();
        double side3 = input.nextDouble();
        String color = input.next();
        boolean fillStatus = input.nextBoolean();
        Triangle a = new Triangle(side1,side2,side3,color,fillStatus);
        System.out.println(a.toString());

    }
}

public class Triangle extends GeometricObject{
    private double side1 = 1.0;
    private double side2 = 1.0;
    private double side3 = 1.0;

    Triangle(){}
    Triangle(double side1,double side2,double side3,String color,boolean filled){
        super(color, filled);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;

    }
    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }
    public double getArea(){
        double p = (this.side1+this.side2+this.side3)/2;
        double s = Math.sqrt(p*(p-this.side1)*(p-this.side2)*(p-this.side3));
        return s;
    }
    public double getPerimeter(){
        return this.side1+this.side2+this.side3;
    }
    public String toString(){
        return super.toString() + "\nTriangle:side1 = " + side1 +
                "\n side2 = "+ side2 +
                "\n side3 = " +side3 +
                "\n area = "+getArea() +
                "\n perimeter = "+ getPerimeter() +
                "\n color = "+getColor();
    }

}

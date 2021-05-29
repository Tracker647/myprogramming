package trial_C10;

public class TestMyPoint {

	public static void main(String[] args) {
		MyPoint a = new MyPoint();
		MyPoint b = new MyPoint(10,30.5);
		a.getCoordinate();
		b.getCoordinate();
		System.out.printf("the distance of a,b is %.1f\n",MyPoint.distance(a.x, a.y, b.x, b.y));
	}

}

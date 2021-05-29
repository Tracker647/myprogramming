package trial_C10;

public class MyPoint {
	public double x;
	public double y;

	MyPoint() {
		this.x = 0;
		this.y = 0;
	}

	MyPoint(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public void getCoordinate() {
		System.out.printf("this coordinate is (%.1f,%.1f)\n", this.x, this.y);
	}

	public double distance(double x, double y) {
		double a = Math.abs(this.x - x);
		double b = Math.abs(this.y - y);
		double d = Math.pow(a, 2) + Math.pow(b, 2);
		return Math.sqrt(d);
	}

	public static double distance(double x1, double y1, double x2, double y2) {
		double a = Math.abs(x1 - x2);
		double b = Math.abs(y1 - y2);
		double d = Math.pow(a, 2) + Math.pow(b, 2);
		return Math.sqrt(d);
	}

}

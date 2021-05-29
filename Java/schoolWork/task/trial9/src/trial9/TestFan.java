package trial9;

public class TestFan {
	public static void main(String[] args) {
		Fan myFan1 = new Fan();
		myFan1.setSpeed(Fan.FAST);
		myFan1.setRadius(10);
		myFan1.setColor("yellow");
		myFan1.setSwitch(true);
		
		Fan myFan2 = new Fan();
		myFan1.setSpeed(Fan.MEDIUM);
		myFan1.setRadius(5);
		myFan1.setColor("blue");
		myFan1.setSwitch(false);
		
		myFan1.getInfoString();
		myFan2.getInfoString();
	}
}

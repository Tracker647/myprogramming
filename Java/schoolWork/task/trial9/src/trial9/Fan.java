package trial9;
import java.util.*;
public class Fan {
	public static final int SLOW = 1;
	public static final int MEDIUM = 2;
	public static final int FAST = 3;
	private int speed = SLOW;
	private boolean on  = false;
	private double radius = 5;
	private String color = "blue";
	
	public Fan() {
		
	}
	
	//accessor
	public void setSpeed(int speed) {
		if(speed!=SLOW && speed!=MEDIUM && speed!=FAST)
		{
			System.out.println("your speed-set not in the channel! Please set speed among 1-3:");
		}
		this.speed = speed;
	}
	
	public void setSwitch(boolean status)
	{
		this.on = status;
	}	
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public void setColor(String color) {
		this.color = color;
	}
	
	//mutator
	public int getSpeed()
	{
		return this.speed;
	}
	
	public boolean getSwitch() {
		return this.on;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public String getColor() {
		return this.color;
	}
	
	public void getInfoString() {
		String status = this.getSwitch()==true?"on":"off";
		System.out.println(this.getClass().getSimpleName() + " info as follows:");
		if(this.getSwitch() == true) {
			System.out.printf("fan speed: %d\nfan color: %s\nfan radius: %.1f\nfan is %s\n",
					this.getSpeed(),this.getColor(),this.getRadius(),status);
		}
		else {
			System.out.printf("fan color: %s\nfan radius: %.1f\nfan is %s\n",
					this.getColor(),this.getRadius(),status);
		}
		System.out.println();
	}
		
}

















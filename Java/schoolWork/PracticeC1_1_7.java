package mylearn;

public class PracticeC1_1_7 {
	public static void main(String[] args) {
		double a=1.0, b=3,s=1;
		int i;
		String str = "S=1";
		for(i=1; i < 7 ; i++ )
		{	
			if(i%2==0)
			{
				s += (a/b);
				str += "+(" + a + "/" + b + ")";
			}
			else
			{
				s-=(a/b);
				str += "-(" + a + "/" + b + ")";
			}
			b += 2;
						
		}
	
		System.out.println(str);
		System.out.println("S*4=");
		System.out.println(s*4);
	}
}

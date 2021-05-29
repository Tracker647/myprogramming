package trial_C10;

public class TestMyinteger {

	public static void main(String[] args) {
		MyInteger a = new MyInteger(7);
		System.out.println(a.getValue());
		System.out.println("a isEven? "+a.isEven());
		System.out.println("Statically, A is a Even? "+ MyInteger.isEven(a.getValue()));
		System.out.println("Statically, A is a Even? "+ MyInteger.isEven(a));
		
		System.out.println("a isOdd? "+a.isOdd());
		System.out.println("Statically, A is a Odd? "+ MyInteger.isOdd(a.getValue()));
		System.out.println("Statically, A is a Odd? "+ MyInteger.isOdd(a));
		
		System.out.println("a isPrime? "+a.isPrime());
		System.out.println("Statically, A is a Prime? "+ MyInteger.isPrime(a.getValue()));
		System.out.println("Statically, A is a Prime? "+ MyInteger.isPrime(a));
		int test = 7;
		System.out.printf("is a Equal with %d ? %b\n",test,a.equals(test));
		System.out.printf("is a Equal with %d ? %b\n",test,a.equals(test));
		char[] strArr = {'2','3','1','4'};
		int strValue = MyInteger.parseInt(strArr);
		System.out.println("the numeric value of str is " + strValue);
		
		String str = "9527";
		strValue = MyInteger.parseInt(str);
		System.out.println("the numeric value of str is "+ strValue);
	}

}

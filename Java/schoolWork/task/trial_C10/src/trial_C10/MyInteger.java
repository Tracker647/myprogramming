package trial_C10;

public class MyInteger {
	private int value;

	MyInteger(int value) {
		this.value = value;
	}

	public int getValue() {
		return this.value;
	}

	public boolean isEven() {
		if (this.value % 2 == 0)
			return true;
		return false;
	}

	public boolean isOdd() {
		if (this.value % 2 == 0)
			return false;
		return true;
	}

	public boolean isPrime() {
		for (int i = 2; i < Math.sqrt(this.value); i++) {
			if (this.value % i == 0)
				return false;
		}
		return true;
	}

	public static boolean isEven(int val) {
		if (val % 2 == 0)
			return true;
		return false;
	}

	public static boolean isOdd(int val) {
		if (val % 2 == 0)
			return false;
		return true;
	}

	public static boolean isPrime(int val) {
		for (int i = 2; i < Math.sqrt(val); i++) {
			if (val % i == 0)
				return false;
		}
		return true;
	}

	public static boolean isEven(MyInteger obj) {
		if (obj.value % 2 == 0)
			return true;
		return false;
	}

	public static boolean isOdd(MyInteger obj) {
		if (obj.value % 2 == 0)
			return false;
		return true;
	}

	public static boolean isPrime(MyInteger obj) {
		for (int i = 2; i < Math.sqrt(obj.value); i++) {
			if (obj.value % i == 0)
				return false;
		}
		return true;
	}

	public boolean equals(int value) {
		return this.value == value ? true : false;
	}

	public boolean equals(MyInteger obj) {
		return this.value == obj.value ? true : false;
	}

	public static int parseInt(char[] str){
		int sum=0;
		int k = 1;
		for(int i = str.length - 1 ;i >= 0;i--){
			sum += Integer.parseInt(String.valueOf(str[i])) * k;
			k*=10;
		}
		return sum;
	}

	public static int parseInt(String str){
		return Integer.parseInt(str);
	}


}

package trial9;

public class TestAccount {
	public static void main(String[] args) {
		Account zdl = new Account(1122,20000);
		Account.setAnnualInterestRate(4.5/100);
		zdl.withdraw(2500);
		zdl.deposit(3000);
		zdl.getBalance();
		zdl.getMonthlyInterest();
		zdl.getAccountCreatedDate();
	}
	
}

package trial9;
import java.util.*;
public class Account {
	private int id;
	private double balance;
	private static double annualInterestRate;
	private Date dateCreated;
	
	
	public Account()
	{
		id = 0;
		balance = 0;
		dateCreated = new Date();
	}
	public Account(int id,int balance){
		this.id = id;
		this.balance = balance;
		dateCreated = new Date();
	}
	//The mutator for id,balance,annualInterestRate
	public void setId(int id) {
		this.id = id;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public static void setAnnualInterestRate(double setvalue) {
		annualInterestRate = setvalue;
	}
	//The accessor for id,balance,annualInterestRate
	public int getId() {
		System.out.println("You id is " + this.id);
		return this.id;
	}
	public double getBalance() {
		System.out.println("You balance is " + this.balance);
		return this.balance;
	}
	public static double getAnnualInterestRate() {
		System.out.println("Now annual interest rate is " + annualInterestRate);
		return annualInterestRate;
	}
	
	//The accessor for dateCreated
	public String getAccountCreatedDate() {
		System.out.println("You account created in " + this.dateCreated);
		return this.dateCreated.toString();
	}
	
	
	public static double getMonthlyInterestRate(){
		double MonthlyInterestRate = annualInterestRate / 12;
		return MonthlyInterestRate;
	}
	
	public double getMonthlyInterest() {
		double MonthlyInterest = this.balance * getMonthlyInterestRate();
		System.out.println("You interest is " + MonthlyInterest);
		return MonthlyInterest;
	}
	
	public void withdraw(double amount) {
		this.balance-= amount;
	}
	
	public void deposit(double amount) {
		this.balance+= amount;
	}
	
	
}

/**
 * (The Account class) Design a class named Account that contains:
 * 
 * ■ A private int data field named id for the account (default 0).
 * ■ A private double data field named balance for the account (default 0).
 * ■ A private double data field named annualInterestRate that stores the current
 * interest rate (default 0). Assume all accounts have the same interest rate.
 * ■ A private Date data field named dateCreated that stores the date when the
 * account was created.
 * ■ A no-arg constructor that creates a default account.
 * ■ A constructor that creates an account with the specified id and initial balance.
 * ■ The accessor and mutator methods for id, balance, and annualInterestRate.
 * ■ The accessor method for dateCreated.
 * ■ A method named getMonthlyInterestRate() that returns the monthly
 * interest rate.
 * ■ A method named getMonthlyInterest() that returns the monthly interest.
 * ■ A method named withdraw that withdraws a specified amount from the
 * account.
 * ■ A method named deposit that deposits a specified amount to the account.
 * 
 * Draw the UML diagram for the class and then implement the class. (Hint: The
 * method getMonthlyInterest() is to return monthly interest, not the interest rate.
 * 
 * Monthly interest is balance * monthlyInterestRate. monthlyInterestRate
 * is annualInterestRate / 12. Note that annualInterestRate is a percentage,
 * e.g., like 4.5%. You need to divide it by 100.)
 * 
 * Write a test program that creates an Account object with an account ID of 1122,
 * a balance of $20,000, and an annual interest rate of 4.5%. Use the withdraw
 * method to withdraw $2,500, use the deposit method to deposit $3,000, and print
 * the balance, the monthly interest, and the date when this account was created.
 * 
 * Author: chill4Eng2Dev 
 * Date: 1/27/2021
 * Book: Introduction to Java Programming, 10th Edition, Y. Daniel Liang
 * Exercise: 9.7
 */

public class EX07_TestAccount {
    
    public static void main(String[] args) {
        
        // initialize an account with an id and initial balance
        Account account = new Account(1122, 20000);
        
        // define the interest rate, withdraw amount, and deposit amount
        account.setAnnualInterestRate(4.5);
        account.withdraw(2500);
        account.deposit(3000);
        
        // print output as described in problem statement
        System.out.printf("The account balance is:    \t$%-5.2f\n", account.getBalance());
        System.out.printf("The monthly interest is:   \t$%-3.2f\n", account.getMonthlyInterest());
        System.out.printf("The account was created on:\t" + account.getDate());
    }

}

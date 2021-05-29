package mylearn.polymorphism;


public class Main01 {
    public static void main(String[] args) {
        Income[] incomes = new Income[] { new Income(3000), new Salary(7500), new State(15000) };
        System.out.println(totalTax(incomes));
    }

    public static double totalTax(Income... incomes) {
        double total = 0;
        for (Income i : incomes) {
            total += i.getTax();
        }
        return total;
    }
}

class Income {
    protected double income;

    public Income(double income) {
        this.income = income;
    }

    public double getTax() {
        return income * 0.1;
    }
}

class Salary extends Income { // 收入包括工资
    public Salary(double income) {
        super(income); // 从父类 Income 继承了属性 income
    }
    @Override
    public double getTax(){
        if(income <= 5000){
            return 0;
        }
        return (income - 5000) * 0.2;
    }
}

class State extends Income {
    public State(double income) {
        super(income); // 从父类 Income 继承了属性 income
    }
    @Override
    public double getTax(){
        return 0;
    }
}
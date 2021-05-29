import java.util.Scanner;

public class TestAccount {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("请输入一个以0结尾的数值序列:");
//        储蓄账户
        SavingAccount mySave = new SavingAccount(6,5000.0);
//        支票(信用卡)账户
        CheckingAccount myCheck = new CheckingAccount(6,5000.0,1000.0);
        mySave.toString();
        myCheck.toString();


    }
}

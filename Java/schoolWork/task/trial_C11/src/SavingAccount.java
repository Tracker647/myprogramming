public class SavingAccount extends Account{
    public SavingAccount(int id,double balance){
        super(id,balance);
    }
    public double withDraw(double withdraw){
            return (this.getBalance()<100)?-1:this.getBalance()-withdraw;
    }
    public  String toString(){
        return "The ID:" + this.getId() + "\nThe balance is " + this.getBalance();
    }
}

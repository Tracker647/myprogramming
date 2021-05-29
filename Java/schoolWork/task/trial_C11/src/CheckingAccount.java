public class CheckingAccount extends Account{
    private double OverDraftLimit;
    public CheckingAccount(int id,double balance,double OverdraftLimit)
    {
        super(id,balance);
        this.OverDraftLimit = OverdraftLimit;   //可用额度
    }

    public double getOverDraftLimit(){
        return OverDraftLimit;
    }
//    设定可用额度
    public void setOverDraftLimit(double OverDraftLimit){
        this.OverDraftLimit = OverDraftLimit;
    }

//    取钱
    public double withDraw(double withdraw) {

        //自动提款机 <100 元是不能够取出来的，我这里用-1表示
//        可用额度不为0,但本金小于100元时
        if (getOverDraftLimit() != 0 && this.getBalance() < 100) {
//            自动提款机，小于100不提取
            this.setBalance(this.getBalance()+this.OverDraftLimit);
//            可用额度都给了本金，故额度清0
            setOverDraftLimit(0);
        }
//        当可用额度为0 且本金小于100元时
        else if (getOverDraftLimit() == 0 && this.getBalance() < 100){
                return -1;      //返回负数，表示不能取钱了!!
        }
        return this.getBalance() - withdraw;
    }

    public String toString(){
        return "The ID:" + this.getId() + "\nThe balance is " + this.getBalance() + "\n可用额度为" + this.getOverDraftLimit();
    }

}
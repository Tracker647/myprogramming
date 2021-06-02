public class Transaction {
    private String who;
    private SmartDate when;
    private double amount;
    public Transaction(String who,SmartDate when,double amount){
        this.who = who;
        this.when = when;
        this.amount = amount;
    }

    public String getWho() {
        return who;
    }

    public SmartDate getWhen() {
        return when;
    }

    public double getAmount() {
        return amount;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "who='" + who + '\'' +
                ", when=" + when +
                ", amount=" + amount +
                '}';
    }
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null) return false;
        if(this.getClass() != obj.getClass()) return false;
        Transaction that = (Transaction) obj;
        if(this.getWho() != that.getWho()) return false;
        if(this.getWhen() != that.getWhen()) return false;
        if(this.getAmount() != that.getAmount()) return false;

        return true;
    }
    public static void main(String[] args) {
        Transaction t103 = new Transaction("Andy",new SmartDate(),25000);
        System.out.println(t103.toString());
    }
}

public class Faculty extends Employee {
    private long officeHours;
    private String rank;

    //构造方法
    public Faculty(long officeHours, String rank, String office, double salary, MyDate DateOfAppointment,
                   String name, String adress, String phone, String email) {

        super(office, salary, DateOfAppointment, name, adress, phone, email);
        this.officeHours=officeHours;
        this.rank=rank;
    }

    public long getOfficeHours() {
        return officeHours;

    }

    public void setOfficeHours(long officeHours) {
        this.officeHours=officeHours;
    }

    public String getRank() {
        return rank;

    }

    public void setRank(String rank) {
        this.rank=rank;
    }

    @Override
    public String toString() {
        return "The Faculty's officeHours is "+officeHours+"\nRank is "+rank+
                "\n"+super.toString();

    }
}

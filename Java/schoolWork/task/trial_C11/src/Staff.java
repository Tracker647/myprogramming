
public class Staff extends Employee {

    private String title;

    //构造方法
    public Staff(String title, String office, double salary, MyDate DateOfAppointment, String name,
                 String adress, String phone, String email) {

        super(office, salary, DateOfAppointment, name, adress, phone, email);
        this.title=title;
    }

    public String getTitle() {
        return title;

    }

    public void setTitle(String title) {
        this.title=title;
    }

    @Override
    public String toString() {
        return "The Staff's title is "+title+"\n"+super.toString();

    }
}


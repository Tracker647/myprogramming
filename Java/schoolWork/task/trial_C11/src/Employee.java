public class Employee extends Person {

    private String office;
    private double salary;
    private MyDate DateOfAppointment;//受聘日期

    //构造方法
    public Employee(String office, double salary, MyDate DateOfAppointment,
                    String name, String adress, String phone, String email) {

        super(name, adress, phone, email);

        this.DateOfAppointment = DateOfAppointment;
        this.salary = salary;
        this.office = office;

    }

    public String getOffice() {
        return office;

    }

    public void setOffice(String office) {
        this.office = office;
    }

    public double getSalary() {
        return salary;

    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getDateOfAppointment() {

        return DateOfAppointment.getYear() + "年" + DateOfAppointment.getMonth()
                + "月" + DateOfAppointment.getDay() + "日";

    }

    @Override
    public String toString() {
        return "The Employee's dateOfAppointment is " + getDateOfAppointment()
                + "\nOffice is " + office + "\nSalary is " + salary + "\n" + super.toString();

    }

}
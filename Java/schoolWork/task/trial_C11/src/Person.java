public class Person {
    private String name;
    private String adress;
    private String phone;
    private String email;

    public Person(String name, String adress, String phone, String email) {
        this.name=name;
        this.adress=adress;
        this.phone=phone;
        this.email=email;
    }

    public Person(String name) {
        this.name=name;
    }

    public String getAdress() {
        return adress;

    }

    public void setAdress(String adress) {
        this.adress=adress;
    }

    public String getPhone() {
        return phone;

    }

    public void setPhone(String phone) {
        this.phone=phone;
    }

    public String getEmail() {
        return email;

    }

    public void setEmail(String email) {
        this.email=email;

    }

    public String toString() {
        return "The Person's name is "+name+"\nAdress is "+adress+
                "\nPhone is "+phone+"\nEmail is "+email;

    }
}
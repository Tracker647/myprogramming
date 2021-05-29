
public class Main01 {
    public static void main(String[] args) {
        Person p = new Person("Xiao Ming", 15);
        System.out.println(p.getAge());
        System.out.println(p.getName());
    }
}

class Person {
    private String name = "Unamed";
    private int age = 10;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    };

    public int getAge() {
        return this.age;
    }

    public String getName() {
        return this.name;
    }
}
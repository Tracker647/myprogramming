public class TestHuman {

    public static void main(String[] args) {

        Person person=new Person("王大狗","垃圾堆","123456789","954378932@qq.com");

        Person student=new Student(4,"王大狗","垃圾堆","123456789","954378932@qq.com");

        Person employee=new Employee("五星街办公室一号",5600,new MyDate(1996,12,17),"王大狗","垃圾堆","123456789","954378932@qq.com");

        Person faculty=new Faculty(8, "二等", "五星街办公室一号",5600,new MyDate(1996,12,17),"王大狗","垃圾堆","123456789","954378932@qq.com");

        Person staff=new Staff("优秀员工","五星街办公室一号",5600,new MyDate(1996,12,17),"王大狗","垃圾堆","123456789","954378932@qq.com");


        System.out.println(person.toString());
        System.out.println();
        System.out.println(student.toString());
        System.out.println();
        System.out.println(employee.toString());
        System.out.println();
        System.out.println(faculty.toString());
        System.out.println();
        System.out.println(staff.toString());

    }

}


import java.util.GregorianCalendar;
public class MyDate {

    private int year;
    private int month;//月份是从0开始的，0代表一月份
    private int day;

    private long eclapseTime;//从格林威治时间1970年1月1日午夜开始流逝的毫秒数

    //无参构造方法，该方法 创建当前日期的 MyDate对象
    public MyDate() {

        //获取当前日期,在这里我直接设置自己当前时间(你们也可以随机设置自己当前日期)
        GregorianCalendar object1=new GregorianCalendar();

        this.year=object1.get(GregorianCalendar.YEAR);
        this.month=object1.get(GregorianCalendar.MONTH);
        this.day=object1.get(GregorianCalendar.DATE);

    }

    //有参构造方法，创建以从1970年1月1日午夜开始流逝的毫秒数为时间的 MyDate对象
    public MyDate(long eclapseTime) {

        GregorianCalendar object2=new GregorianCalendar();

        //设置从格林威治时间算起的一个特定时间
        object2.setTimeInMillis(eclapseTime);

        this.year=object2.get(GregorianCalendar.YEAR);
        this.month=object2.get(GregorianCalendar.MONTH);
        this.day=object2.get(GregorianCalendar.DATE);

    }

    //有参构造方法，创建带指定 （年，月，日）的 MyDate对象
    public MyDate(int year, int month, int day) {
        this.year=year;
        this.month=month;
        this.day=day;
    }

    public int getYear() {
        return year;

    }

    public int getMonth() {
        return month;

    }

    public int getDay() {
        return day;

    }

    //设置一个从格林威治时间1970年1月1日午夜开始流逝的毫秒数
    public void setDate(long eclapseTime) {
        this.eclapseTime=eclapseTime;

    }
}


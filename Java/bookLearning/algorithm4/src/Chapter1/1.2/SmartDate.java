import java.time.LocalDate;
import java.util.Date;

public class SmartDate {
    private static int month;
    private static int day;
    private static int year;
    private static int[] monthOfYear = {31,28,31,30,31,30,31,31,30,31,30,31};
    private final String[] WEEK = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    public SmartDate(){
        LocalDate date = LocalDate.now();
       month = date.getMonthValue();
       day = date.getDayOfMonth();
       year = date.getYear();
    }
    public SmartDate(int d,int m,int y) {
        month = m;
        day = d;
        year = y;
        if(illegalDate()){
            throw new RuntimeException("illegal date input");
        }
        //            闰年检测
        if(isLunarYear(this.year()))
            monthOfYear[1] = 29;
    }

    public boolean illegalDate() {
            if(this.year() < 0)
                return true;
            if(this.month() < 1 || this.month() > 12)
                return true;
            if(this.day() < 1 || this.day() > monthOfYear[this.month() - 1])
                return true;
            return false;
    }
    public static boolean isLunarYear(int year){
        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return true;
        return false;
    }
    public int month(){
        return month;
    }
    public int day(){
        return day;
    }
    public int year(){
        return year;
    }
    public String dayOfTheWeek(){
//        计算自2000年1月1日到现在的日数
        int sum = 0;
        int year = 2000;
        while(year < this.year()) {
            if(isLunarYear(year))
                sum += 366;
            else
                sum += 365;
            year++;
        }
        for(int i = 0 ; i <= this.month() - 2; i++){
            sum += monthOfYear[i];
        }
        sum += this.day() - 1;
        int week = sum % 7;
        return WEEK[week];
    }
    public String toString(){
        return month() + "/" + day() + "/" + year();
    }
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null) return false;
        if(this.getClass() != obj.getClass()) return false;

        SmartDate that = (SmartDate)obj;
        if(this.day()!= that.day()) return false;
        if(this.month()!= that.month()) return false;
        if(this.year()!= that.year()) return false;
        return true;
    }
    public static void main(String[] args){
        SmartDate date = new SmartDate();
        System.out.println(date.toString());
        System.out.println(date.dayOfTheWeek());
    }
}

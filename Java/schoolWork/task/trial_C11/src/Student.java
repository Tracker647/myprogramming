public class Student extends Person {

    private int classState;

    public final static int FRESHMAN=1;//大一新生
    public final static int SOPHOMORE=2;//大二学生
    public final static int JUNIOR=3;//大三学生
    public final static int SENIOR=4;//大四学生


    public Student(int classState, String name, String adress, String phone, String email) {
        super(name, adress, phone, email);
        this.classState=classState;

    }

    public int getClassState() {
        return classState;

    }

    public void setClassState(int classState) {
        this.classState=classState;
    }

    @Override
    public String toString() {
        return "The Student's classState is "+classState+"\n"+super.toString();

    }
}

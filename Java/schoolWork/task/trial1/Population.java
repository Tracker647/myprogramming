public class Population { // 1.11
    public static void main(String args[]) {
        int pop = 312032486;
        int year;
        int yearsec = 31536000;
        int yearBorn = yearsec / 7;
        int yearMov = yearsec / 45;
        int yearDead = yearsec / 13;

        for (year = 1; year < 5; year++) {
            pop = pop + (yearBorn + yearMov - yearDead) * year;
            System.out.printf("The population %d years later is %d\n", year, pop);
        }

    }
}
import java.util.Scanner;

public class assignGrades {
    public static void main(String args[]) {
        int i;
        char grade;
        System.out.println("Enter the number of students:");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] scores = new int[num];
        System.out.println("Enter " + num + " scores: ");
        for (i = 0; i < num; i++)
            scores[i] = input.nextInt();
        int best = max_arr(scores);
        for (i = 0; i < num; i++) {
            if (scores[i] >= best - 10)
                grade = 'A';
            else if (scores[i] >= best - 20)
                grade = 'B';
            else if (scores[i] >= best - 30)
                grade = 'C';
            else if (scores[i] >= best - 40)
                grade = 'D';
            else
                grade = 'F';
            System.out.println(" Student " + i + " score is " + scores[i] + " and grade is " + grade);
        }

    }

    public static int max_arr(int[] scores) {
        int max = scores[0];
        for (int i = 1; i < scores.length; i++) {
            if (max < scores[i])
                max = scores[i];
        }
        return max;
    }
}

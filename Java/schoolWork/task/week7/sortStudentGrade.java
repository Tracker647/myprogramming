public class sortStudentGrade {
    public static void main(String args[]) {
        char[][] answers = { { 'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
                { 'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D' },
                { 'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D' },
                { 'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D' },
                { 'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
                { 'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
                { 'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
                { 'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D' } };
        char[] keys = { 'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D' };
        int i, j;
        int[][] studentCorrectCount = new int[answers[0].length - 1][2];
        for (i = 0; i < answers.length ; i++) {
            studentCorrectCount[i][0] = i;
            studentCorrectCount[i][1] = 0;
            for (j = 0; j < answers[i].length; j++) {
                if (answers[i][j] == keys[j])
                    studentCorrectCount[i][1]++;
            }

        }
        sort(studentCorrectCount);

    }

    public static void sort(int[][] arr) {
        int i, j,k, min, minIndex;
        int[] temp;
        // for (i = 0; i < arr.length - 1; i++) {
        //     System.out.printf("arr[%d]= { %d %d }\n", i, arr[i][0], arr[i][1]);
        // }
        for (i = 0; i < arr.length - 1; i++) {
            min = arr[i][1];
            minIndex = i;
            // System.out.printf("assuming min is arr[%d] = { %d %d }\n", minIndex, arr[minIndex][0],  min);
            for (j = i + 1; j < arr.length - 1; j++) {
                if (arr[j][1] < min) {
                    min = arr[j][1];
                    minIndex = j;
                }
            }
            // System.out.printf("find min is arr[%d] = { %d %d }\n", minIndex, arr[minIndex][0],  min);
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            // System.out.printf("Now arr is\n");
            // for (k = 0; k < arr.length - 1; k++) {
            //     System.out.printf("arr[%d]= { %d %d }\n", k, arr[k][0], arr[k][1]);
            // }
        }
        for (i = 0; i < arr.length - 1; i++) {
            for (j = 0; j < arr[i].length - 1; j++)
                System.out.println("Student " + arr[i][0] + " 's correct count is " + arr[i][1]);
        }
    }
}

package Chapter1;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Practice1122 {
    static int count = 0;
    public static void main(String[] args) {
        ArrayList<Integer> whitelist  = new ArrayList<Integer>();
        ArrayList<Integer> keylist  = new ArrayList<Integer>();
        whitelist = readFileArray("src/Chapter1/tinyW.txt");
        keylist = readFileArray("src/Chapter1/tinyT.txt");
        String mode = "-";
        System.out.println("mode is "+ mode);
        for(int key: keylist){
//            System.out.printf("Throw key: %d\n " , key);
           binarySearch(key,whitelist,mode);
        }
    }
    /**
     * 从文件中提取出一维数组,接受一个文件名
     */
    public static ArrayList<Integer> readFileArray(String filename){
//        创建用于存放的数组和对应的File对象
        ArrayList<Integer> list  = new ArrayList<Integer>();
        File file = new File(filename);
        try{

            BufferedReader reader = new BufferedReader(new FileReader(file));
            String text = null;

//            将read读取出来的每行数字字符转化为整数
            while((text = reader.readLine()) != null){
                list.add(Integer.parseInt(text));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return list;
    }

    public static void binarySearch(int key,  ArrayList<Integer>  arr,String mode) {
        int result = rank(key, arr, 0, arr.toArray().length - 1);
        boolean isIn = false;
        for(int i: arr){
            if(i == result)
                isIn = true;
        }
//        System.out.printf("%d is in arr? %b\n",result,isIn);

        if (isIn == true && mode == "-")
            System.out.printf("%d in whitelist\n",result);
        else if (isIn == false && mode == "+")
            System.out.printf("%d not in whitelist\n",result);

    }

    public static int rank(int key, ArrayList<Integer> a, int lo, int hi) {
        count ++;
        int mid = lo + hi / 2;
//        System.out.printf("current low: %d high: %d recursion depth: %d\n",lo,hi,count);
//       如果key在数组中，返回数组对应值，如果key不在数组中,返回key
        if (key == a.get(mid))
            return a.get(mid);
        else if (key < a.get(mid) && key > a.get(lo))
            rank(key, a, lo, mid);
        else if (key > a.get(mid) && key < a.get(hi))
            rank(key, a, mid, hi);
        return key;
    }
}

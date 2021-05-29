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

        binarySearch(key,whitelist,"+");

    }
    public static  ArrayList<Integer> readFileArray(String filename){
        ArrayList<Integer> list  = new ArrayList<Integer>();
        File file = new File(filename);
        BufferedReader reader = null;

        try{
            reader = new BufferedReader(new FileReader(file));
            String text = null;

            while((text = reader.readLine()) != null){
                list.add(Integer.parseInt(text));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try{
                if(reader != null){
                    reader.close();
                }
            }catch (IOException e){

            }
        }
        return list;
    }

    public static void binarySearch(int key, int[] arr,String mode) {
        int result = rank(key, arr, 0, arr.length - 1);
        boolean isIn = false;
        for(int i: arr){
            if(i == result)
                isIn = true;
        }
        System.out.printf("%d is in arr? %b\n",result,isIn);

        if (isIn == true && mode == "-")
            System.out.printf("%d in whitelist\n",result);
        else if (isIn == false && mode == "+")
            System.out.printf("%d not in whitelist\n",result);

    }

    public static int rank(int key, int[] a, int lo, int hi) {
        count ++;
        int mid = lo + hi / 2;
//        System.out.printf("current low: %d high: %d recursion depth: %d\n",lo,hi,count);
//       如果key在数组中，返回数组对应值，如果key不在数组中,返回key
        if (key == a[mid])
            return a[mid];
        else if (key < a[mid] && key > a[lo])
            rank(key, a, lo, mid);
        else if (key > a[mid] && key < a[hi])
            rank(key, a, mid, hi);
        return key;
    }
}

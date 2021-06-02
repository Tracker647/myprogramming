package Chapter1;

import java.io.*;
import java.util.ArrayList;

public class Practice1128 {
    public static void main(String[] args) {
        ArrayList <Integer> whiteList = readFileArray("src/Chapter1/tinyW.txt");
        ArrayList <Integer> testList = readFileArray("src/Chapter1/tinyT.txt");
        whiteList = removeDuplicates(whiteList);
        testList = removeDuplicates(testList);

    }
    public static <T> ArrayList<T> removeDuplicates(ArrayList<T> list){
        ArrayList<T> newlist = new ArrayList<T>();
        for(T element : list){
            if(!newlist.contains(element)){
                newlist.add(element);
            }
        }
        return newlist;
    }
    public static int binarySearch(int key, ArrayList<Integer> arr, int lo, int hi){
        int mid = lo + hi /2;
        if(key == arr.get(mid)) return key;
        else if (key > lo && key < mid){binarySearch(key, arr, lo, mid);}
        else if (key < hi && key > mid){binarySearch(key, arr, mid,hi);}
        return -1;
    }
    public static ArrayList<Integer> readFileArray(String filename){
        File file = new File(filename);
        ArrayList<Integer> list = new ArrayList<Integer>();
        try{
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String text = null;
            while((text = reader.readLine()) != null)
                list.add(Integer.parseInt(text));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return list;
    }
}

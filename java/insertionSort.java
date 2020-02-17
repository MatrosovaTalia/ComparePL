import java.io.*;
import java.util.Scanner;

public class insertionSort {
    public static void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int current = array[i];
            int j = i - 1;
            while (j >= 0 && current < array[j]) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = current;
        }
    }

    public static void main(String[] args) throws IOException {
        final int N = 1000;
        File array = new File("array.txt");
        Scanner scanner = new Scanner(array);
        int [] arr = new int [N];
        int i = 0;

        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }
        insertionSort(arr);
    }
}

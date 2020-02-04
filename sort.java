import java.util.Arrays;
import java.io.*;
import java.util.Scanner;

public class sort {
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

    public void mergeSort(int[] array, int left, int right) {
        if (right <= left) return;
        int mid = (left+right)/2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }

    void merge(int[] array, int left, int mid, int right) {
        int lengthLeft = mid - left + 1;
        int lengthRight = right - mid;

        int leftArray[] = new int [lengthLeft];
        int rightArray[] = new int [lengthRight];

        for (int i = 0; i < lengthLeft; i++)
            leftArray[i] = array[left+i];
        for (int i = 0; i < lengthRight; i++)
            rightArray[i] = array[mid+i+1];

        int leftIndex = 0;
        int rightIndex = 0;

        for (int i = left; i < right + 1; i++) {
            if (leftIndex < lengthLeft && rightIndex < lengthRight) {
                if (leftArray[leftIndex] < rightArray[rightIndex]) {
                    array[i] = leftArray[leftIndex];
                    leftIndex++;
                }
                else {
                    array[i] = rightArray[rightIndex];
                    rightIndex++;
                }
            }
            else if (leftIndex < lengthLeft) {
                array[i] = leftArray[leftIndex];
                leftIndex++;
            }
            else if (rightIndex < lengthRight) {
                array[i] = rightArray[rightIndex];
                rightIndex++;
            }
        }
    }

    int[] countElements(int[] input, int k) {
        int[] c = new int[k + 1];
        Arrays.fill(c, 0);
        for (int i : input) {
            c[i] += 1;
        }

        for (int i = 1; i < c.length; i++) {
            c[i] += c[i - 1];
        }

        return c;
    }

    public void countingSort(int[] arr, int range) {
        int[] count = new int[range];
        Arrays.fill(count, 0);
        for (int i : arr) {
            count[i] += 1;
        }

        int k = 0;
        for (int i = 0; i < range; i++){
            while(count[i] > 0){
                arr[k] = i;
                k++;
                count[i]--;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        final int N = 1000;
        File array = new File("array.txt");
        Scanner scanner = new Scanner(array);
        int [] arr = new int [N];
        int i = 0;
        long start, end;
        double insertion_time, merge_time, counting_time;

        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }



        start = System.nanoTime();
       insertionSort(arr);
        end = System.nanoTime();
        insertion_time = (double) (end - start) / 1_000_000_000;

        i = 0;
        scanner = new Scanner(array);
        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }

        sort obj = new sort();
        start = System.nanoTime();
       obj.mergeSort(arr, 0, arr.length - 1);
        end = System.nanoTime();

        merge_time = (double) (end - start) / 1_000_000_000;

        i = 0;
        scanner = new Scanner(array);
        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }

        start = System.nanoTime();
        obj.countingSort(arr, 1000);
        end = System.nanoTime();
        counting_time = (double) (end - start) / 1_000_000_000;


        // System.out.println(Arrays.toString(arr));
        // System.out.println("Hello, I am java file!");

       String output = String.format("Java: Insertion sort time: %f\n" +
               "Java: Merge sort time: %f\n" +
               "Java: Counting sort time: %f\n", insertion_time, merge_time, counting_time);
       File file = new File("time-measured.txt");
       FileWriter fr = new FileWriter(file, true);
       fr.write(output);
       fr.close();

    }

}

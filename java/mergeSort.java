import java.io.*;
import java.util.Scanner;

public class mergeSort {
    public void merge_sort(int[] array, int left, int right) {
        if (right <= left) return;
        int mid = (left+right)/2;
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
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

    public static void main(String[] args) throws IOException {
        final int N = 1000;
        File array = new File("array.txt");
        Scanner scanner = new Scanner(array);
        int [] arr = new int [N];
        int i = 0;

        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }
        mergeSort obj = new mergeSort();
        final double startTime = System.nanoTime() / 1000000;
        obj.merge_sort(arr, 0, arr.length - 1);
        final double endTime = System.nanoTime() / 1000000;

        System.out.println((endTime - startTime));
    }
}

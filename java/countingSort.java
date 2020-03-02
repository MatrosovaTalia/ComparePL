import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class countingSort {


    public void counting_sort(int[] arr, int range) {
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

        while(scanner.hasNextInt()){
            arr[i++] = scanner.nextInt();
        }
        countingSort obj = new countingSort();

        final double startTime = System.nanoTime() / 1000000;

        obj.counting_sort(arr, 1000);

        final double endTime = System.nanoTime() / 1000000;

        System.out.println("Counting sort: " + (endTime - startTime) + "ms");
    }
}

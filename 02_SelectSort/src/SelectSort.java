import java.util.Random;

public class SelectSort {

    static void ss() {
        int c = 0, m = 0;
        Random rand = new Random();
        int n = 100;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand.nextInt(100);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int sh = 0; sh < n; sh++) System.out.print(a[sh] + " ");
            int minI = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[minI]) {//searching for an index of the smallest element in the list, that's left
                    c++;
                    minI = j;
                }
            int tmp = a[minI];
            a[minI] = a[i];
            a[i] = tmp;
            m++;

            System.out.println();
        }
        System.out.println("Comparisons: " + c + " Moves: " + m);
    }

    public static void main(String[] args) {
        ss();
    }
}

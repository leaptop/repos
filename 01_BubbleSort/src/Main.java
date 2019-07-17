import java.util.Random;

public class Main {
    static void bs() {
        int c = 0, m = 0;
        Random rand = new Random();
        int n = 10;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand.nextInt(50);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int sh = 0; sh < n; sh++) System.out.print(a[sh] + " ");
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {//this is it. Ypu have to compare two neighboring elements. This is authentic bubble
                    int tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                    m++;
                }
                c++;
            }
            System.out.println();
        }
        System.out.println("Comparisons: " + c + " Moves: " + m);
    }

    public static void main(String[] args) {
        bs();
    }
}

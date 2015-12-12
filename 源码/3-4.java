import java.util.Scanner;

/**
 * Created by xiami on 2015/11/15.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                arr[i][j] = scan.nextInt();
            }
        }
        if (n == 1) {
            System.out.println(arr[0][0]);
            System.out.println(arr[0][0]);
            return;
        } else if (n == 2) {
            int max = arr[1][0] > arr[1][1] ? arr[1][0] : arr[1][1];
            System.out.println(arr[0][0] + max);
            System.out.println(arr[0][0] + " " + max);
            return;
        }
        StringBuilder sb[][] = new StringBuilder[n][n];

        for (int i = 0; i < n; i++) {
            sb[n - 1][i] = new StringBuilder().append(arr[n - 1][i]).append(' ');
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (arr[i + 1][j] > arr[i + 1][j + 1]) {
                    sb[i][j] = new StringBuilder().append(arr[i][j]).append(' ').append(sb[i + 1][j]);
                    arr[i][j] += arr[i + 1][j];
                } else {
                    sb[i][j] = new StringBuilder().append(arr[i][j]).append(' ').append(sb[i + 1][j + 1]);
                    arr[i][j] += arr[i + 1][j + 1];
                }
            }
        }
        System.out.println(arr[0][0]);
        System.out.println(sb[0][0].toString());
    }
}

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the towerBreakers function below.
     */
    static int towerBreakers(int[] arr) {
        int nimSum = 0;
        for(int a: arr){
            if(a!=1){
               int count =0;
               boolean flag= true;
                for(int i=2;i<=a;i++){
                        if(a%i==0){
                            if(i!=2 ||  flag){
                                count++;
                                flag=false;
                            }
                            a/=i;
                            i--;
                        }
                }
                nimSum^=count;
            }
        }
        if(nimSum==0)
            return 2;
        return 1;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(scanner.nextLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int arrCount = Integer.parseInt(scanner.nextLine().trim());

            int[] arr = new int[arrCount];

            String[] arrItems = scanner.nextLine().split(" ");

            for (int arrItr = 0; arrItr < arrCount; arrItr++) {
                int arrItem = Integer.parseInt(arrItems[arrItr].trim());
                arr[arrItr] = arrItem;
            }

            int result = towerBreakers(arr);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}

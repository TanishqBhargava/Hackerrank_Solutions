import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gameOfThrones function below.
    static String gameOfThrones(String s) {
        if(s==null || s.length()==0)
            return "NO";
        int[] a = new int[26];
        char[] c = s.toCharArray();
        int count=0;
        for(int i=0; i<c.length; i++) {
            if(a[c[i]-'a']==0)
                a[c[i]-'a']++;
            else
                a[c[i]-'a']=0;
        }
        for(int i=0; i<a.length; i++) {
            if(a[i]!=0)
                count++;
        }
        if(count>1)
            return "NO";
        return "YES";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = gameOfThrones(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

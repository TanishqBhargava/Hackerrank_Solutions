import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static Set<Character> a;
    static Set<Character> b;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for(int i = 0; i < n; i++) {
            a = new HashSet<Character>();
            b = new HashSet<Character>();
            for(char c : scan.next().toCharArray()) {
                a.add(c);
            }
            for(char c : scan.next().toCharArray()) {
                b.add(c);
            }

            // store the set intersection in set 'a'
            a.retainAll(b);

            System.out.println( (a.isEmpty()) ? "NO" : "YES" );
        }
        scan.close();
    }
}

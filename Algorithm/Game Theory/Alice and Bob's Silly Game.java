import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Solution {
    static int sieve(int grens){
        int primes = 0;
        boolean[] catch_the_sieve = new boolean[grens+1];
        for (int x = 2; x <= grens; x++){
            if (catch_the_sieve[x] == false){
                primes++;
                for (int i = x; i <= grens; i += x){
                    catch_the_sieve[i] = true;
                    }
                }
            }
        return primes;
        }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int g = in.nextInt();
        for(int a0 = 0; a0 < g; a0++){
            int n = in.nextInt();
            //    System.out.println(sieve(n));
            if(sieve(n) % 2 == 0)
                System.out.println("Bob");
            else
                System.out.println("Alice"); 
        }
    }
}

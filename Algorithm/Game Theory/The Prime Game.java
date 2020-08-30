import java.io.*;  
import java.util.*;  
import java.text.*;  
import java.math.*;  
import java.util.regex.*;  

public class Solution {  

    public static void main(String[] args) {  
        int t = ni();  
        for(int i=0; i<t; i++){  
            System.out.println(solve());  
        }  
    }  

    public static int[] values = new int[]{0, 0, 1, 1, 2, 2, 3, 3, 4};  
    public static String solve(){  
        int n = ni();  
        long ak;  
        long nimber = 0; //or grundy number  
        for(int i=0; i<n; i++){  
            ak = nl();  
            nimber ^= values[(int) (ak % values.length)];
        }  
        if(nimber > 0) return "Manasa";  
        return "Sandy";  
    }  

    public static Scanner sc = new Scanner(System.in);  
    public static int ni(){  
        return sc.nextInt();  
    }  
    public static long nl(){  
        return sc.nextLong();  
    }  
}

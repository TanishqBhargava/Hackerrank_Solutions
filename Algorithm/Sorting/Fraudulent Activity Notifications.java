import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int[] hash = new int[210];
        int[] a =  new int[n];
        if (d>=n) {
            System.out.println(0);
            return;
        }
        for(int i=0; i<d; i++){
            a[i]=in.nextInt();
            hash[a[i]]++;
        }
        int sol=0;
        for(int i=d; i<n; i++){
            a[i] = in.nextInt();
            int count=0;
            double ans=0;
            for(int j=0; j<210; j++){
                count+=hash[j];
               // if (count>=d/)
                if (2*count>=d) {
                    if (2*count==d){
                        //if (hash[j]==0) continue;
                        ans=j;
                    } else{
                        if(ans!=0){
                            ans=(ans+j)/2;
                        } else{
                            ans=j;
                        }
                        //ans=j;
                        break;
                    }
                    
                }
            }
           // System.out.println(ans+" "+a[i]);
            if (a[i]>=2*ans) sol++;
            
            hash[a[i]]++;
            hash[a[i-d]]--;
        }
        System.out.println(sol);
        
    }
}

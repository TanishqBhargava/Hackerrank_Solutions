import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

public static void main(String[] args) {

    Scanner in = new Scanner(System.in);
       LinkedList<Integer> q=new LinkedList<Integer>();
    int n = in.nextInt();
    int m = in.nextInt();
    int c[] = new int[m];
          for(int i=0;i<n;i++){
        q.add(i);



    }
       // System.out.println(q);
        for(int c_i=0; c_i < m; c_i++){
        c[c_i] = in.nextInt();
      //  System.out.println(c[c_i]);
int index=q.indexOf(c[c_i]); q.set(index,-1);

    }
    if(n==m){
        System.out.println("0");
    }
   // System.out.println((11/2));
    else{ 
        int max=0;int min;
       //System.out.println(q);
        int size=q.size();
        int flag=0;
        int previous=(-2);
       // System.out.println(size);
        for(int i=0;i<size;i++){
          int k=q.poll();
          //  System.out.println(i+" "+k);
            //System.out.println(k);
            if(i==(size-1)&& k!=(-1)){
                int max2=Math.abs(i-previous);
                if(max2>max){
                    max=max2;
                }

            }
          else  if(i!=0 &&previous==(-2) && k==(-1)){

                previous=i;
                flag=1;
                max=i;
            }
            else if(i==0 && k==(-1) && previous!=(-1)){
                previous=0;
              //  System.out.println(i+" "+"hit1");
                flag=1;
            }
            else if(i!=0 && flag==1 && k==(-1) && previous!=(-1)){
            int pattern=((i+previous)/2);
            if(pattern!=previous){
                int min1=Math.abs(pattern-previous);
                int min2=Math.abs(pattern-i);
              //  System.out.println(min1+" "+min2+" minimiumhit");
               if(min1<=min2){
                   min=min1;
               }
                else{
                    min=min2;
                }
                if(min>max){
                    max=min;}
                    }
                previous=i;
                       //System.out.println(i+" "+"hit2"+max);
                }
                else if(i!=0 && flag==0 && k==(-1)&& previous!=(-1)){
                    flag=1;
                    previous=i;
                        //    System.out.println(i+" "+"hit3");

                }
               // System.out.println(max);
            }

          System.out.println(max);
        }
    }
}

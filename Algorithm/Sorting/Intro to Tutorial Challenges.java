import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution 
{
  public static void main(String[] args) 
    {
      Scanner in = new Scanner(System.in);
      int goal = in.nextInt();
      in.nextInt();
      int counter = 0;
      while(in.hasNextInt())
      {
        if(in.nextInt() == goal) 
        {
          System.out.println(counter);
          break;
        }
        counter += 1;
      }
   }
}

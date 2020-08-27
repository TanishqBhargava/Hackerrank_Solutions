import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String solve(int year){
        
        //Change this to find any day of the year. 
        int dayToFind = 256;
        
        //Store days of month in a collection we can use for calculations later
        int [] daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};

        //If year is greater then 1918, lets use gregorian calendar
        if(year > 1918){
            
            // Gregorian: Is leap year if divisible by 400, or divisible by 4 but not 100
            if( (year % 400 == 0) || ( year % 4== 0 && year % 100 != 0   )) {
                daysInMonths[1] = 29;
            } 
            
        } else if(year <= 1917) { //Use Julian calendar instead
            
             //Julian: Is leap year if divisible by 4
            if( year % 4 == 0) {
                daysInMonths[1] = 29;
            }
            
        } else {//is 1918, do special case for the switch in calendars from Julian to Gregorian
            //Feb started on day 14, meaning there were 29 - 14 = 15 days in this month for this year
            daysInMonths[1] = 15;
        }
        
        //keep memory of the sum of the days in each month   
        int runningTotal = 0;
        
        //keep memory of which month we are in, not 0 indexing
        int currentMonth = 0;
        
        /*Loop through the months, and sum the days for each, checking if we exceeded the day we are trying to find. If we did, we know that day is in the current month. Then we just do some subtractions to get the actual day */
        for(int i = 0; i < 13; i++) {
                
           //Add the running total with this current month
           runningTotal += daysInMonths[i];
           currentMonth += 1;
                                                                                
           //If we exceeded the day count, we know its in this month so break.
           if(runningTotal > dayToFind) {  
              break;
           }
        }
        
        //Now lets subtract to get the result, with an offset of 1
        int dayOfMonth = (daysInMonths[currentMonth] - (runningTotal - dayToFind)) - 1;  
        
        //Format Day and month
        String day = (dayOfMonth < 10) ? "0"+dayOfMonth : ""+dayOfMonth;   
        String month = (currentMonth < 10) ? "0"+currentMonth : ""+currentMonth;
        return day +"." + month + "." + year;
            
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int year = in.nextInt();
        String result = solve(year);
        System.out.println(result);
    }
}

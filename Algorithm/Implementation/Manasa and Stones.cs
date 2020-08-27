using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

class Solution {
    static void Main(String[] args) {
        var cases = Convert.ToInt32(Console.ReadLine());
        for(var ii = 0; ii < cases; ii++){
            var stones = Convert.ToInt32(Console.ReadLine()) - 1;
            var one = Convert.ToInt32(Console.ReadLine());
            var two = Convert.ToInt32(Console.ReadLine());
            var a = Math.Min(one, two);
            var b = Math.Max(one, two);
            var current = a * stones;
            var max = b * stones;
            var difference = b - a;
            if(a == b){
                Console.WriteLine(current);
            }
            else{
                var ansString = new StringBuilder();
                while(current <= max){
                    ansString.Append(current.ToString() + " ");
                    current += difference;
                }
                Console.WriteLine(ansString);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution { 
    private static bool isSorted (int[] pArray, int pIndex) {
        if (pIndex == 0) {return true;}
        bool sorted = true; 
        for (int i=0; i<pIndex&&sorted;i++) {
            if (pArray[i] > pArray[i+1]) {
                sorted = false; 
            }
        }
        return sorted; 
        
    }
    public static void insertionSort (int[] A) { 
        var j = 0; 
        for (var i = 1; i < A.Length; i++) { 
            var value = A[i]; 
            j = i - 1; 
            while (j >= 0 && value < A[j]) { 
                A[j + 1] = A[j];
                j = j - 1; 
            } 
            A[j + 1] = value;
            if (!Solution.isSorted(A, i-1)) {
                Console.WriteLine("Sort Failed at index: " + (i-1) + " string: '{0}",
                                     string.Join(", ", A.Select(v => v.ToString())) + "'");
            }
        } 
        Console.WriteLine(string.Join(" ", A)); 
    }

    static void Main(string[] args) { 
        Console.ReadLine(); 
        int [] _ar = (from s in Console.ReadLine().Split() select Convert.ToInt32(s)).ToArray();
        insertionSort(_ar); 
    }
}

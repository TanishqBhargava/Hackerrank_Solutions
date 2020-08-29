import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /*
        1. create an array of size 100000, signifying min-heap data structure
        2. create int count = 0, signifying the number of items in the array & index of the last item

        for adding item:
        1. as the total number of items will always < 100000, so we do not need to check the exceeding size limit
        2. just add the item into count+1
        3. perform rising of item
        4. count++

        for rising:
        1. accept index of item & the array
        2. while the index > 1, if the array[index] < array[index//2], perform swap
        3. else, break the loop, because the elements are already in min-heap order

        for deleting item:
        1. deleting item guarantees that item will always be in the heap, so no checking required
        2. iterate every item in the array to find the item to be deleted
        3. when found, swap the element in the last index to this index of deleted item
        4. perform sinking of the item
        5. count--

        for sinking:
        1. accept index of item & the array & total number of items
        2. find the minimum of smallest index from the original index
        3. if array[smallest] < array[index], perform swap
        4. else, break the loop, min-heap achieved
        5. set the index = smallest
        6. do as long as 2 * index < max
         */

        Scanner scanner = new Scanner(System.in);
        int[] array = new int[100000];
        Set<Integer> added = new HashSet<>();
        int count = 0;
        int Q = scanner.nextInt();
        scanner.nextLine();

        while (Q>0) {
            String result = scanner.nextLine();
            Scanner resultScanner = new Scanner(result);
            Integer item;

            switch (Integer.parseInt(resultScanner.next())) {
                case 1:
                    item = Integer.parseInt(resultScanner.next());
                    if (!added.contains(item)) {
                        added.add(item);
                        array[count+1] = item;
                        count++;
                        rising(array, count);
                    }
                    break;

                case 2:
                    item = Integer.parseInt(resultScanner.next());
                    for (int i = 1; i <= count; i++) {
                        if (array[i] == item) {
                            swap(array, i, count);
                            added.remove(item);
                            count--;
                            sinking(array, i, count);
                            break;
                        }
                    }
                    break;

                case 3:
                    System.out.println(array[1]);
                    break;
            }
            Q--;
        }

    }

    static void rising(int[] array, int index) {
        // do until index reaches the top of the heap
        while (index > 1) {
            if (array[index] < array[index/2]) {
                swap(array, index, index/2);
                index = index /2;
            } else {
                break;
            }
        }
    }

    static void sinking(int[] array, int index, int max) {
        while (2*index <= max) {
            int smallestChild = getSmallestIndex(array, index, max);
            if (array[smallestChild] < array[index]) {
                swap(array, smallestChild, index);
                index = smallestChild;
            } else {
                break;
            }
        }
    }

    static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }


    static int getSmallestIndex(int[] array, int index, int max) {
        // happens 2*index is the last element of the array
        if (2*index == max || array[2*index] < array[2*index+1]) {
            return 2*index;
        } else {
            return 2*index +1;
        }
    }
}

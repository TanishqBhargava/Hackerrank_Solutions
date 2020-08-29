import java.util.*;

public class Play {
    public static int binaryEquivalent(String s) {
        String binaryBuilder;
        char[] bits = {'0','0','0','0','0','0','0','0','0','0'};
        char character;
        for (int i = 0; i < s.length(); i++) {
            character = s.charAt(i);
            bits[character-48] = '1';           //In ASCII, '0' = 48. 
            //Here if a number is present, we are putting a 1 in place of a 0 at that index.
        }
        binaryBuilder = ""+bits[0]+bits[1]+bits[2]+bits[3]+bits[4]+bits[5]+bits[6]+bits[7]+bits[8]+bits[9];
        return Integer.parseInt(binaryBuilder,2);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        long[] frequency = new long[1024];
        int binary;
        int size = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");   //Only to solve an input related error of scanner.
        long  counter = 0l;

        for (int i = 0; i < size; i++) {
            String ticketsItem = scanner.nextLine();
            binary = binaryEquivalent(ticketsItem);
            frequency[binary] = frequency[binary] + 1l;
        }
        for (int i = 0; i < 1023; i++) {
            if(frequency[i]==0)
                continue;
            for(int j=i+1;j<1024;j++) {
                if((i|j)==1023)
                    counter += frequency[i]*frequency[j];
            }
        }
        counter += frequency[1023]*(frequency[1023]-1)/2;
        System.out.println(counter);
        scanner.close();
    }
}

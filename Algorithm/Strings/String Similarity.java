import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Solution {
  public static void main(String[] args) {
    try (final Scanner scanner = new Scanner(System.in)) {
      final int t = Integer.parseInt(scanner.nextLine());
      Stream.generate(scanner::nextLine).limit(t).mapToLong(Solution::stringSimilarity).forEach(System.out::println);
    }
  }

  public static long stringSimilarity(final String s) {
    final int n = s.length();
    final int[] z = new int[n];
    for (int i = 1, l = 0, r = 0; i < n; i++) {
      if (i > r) {
        l = r = i;
        while (r < n && s.charAt(r - l) == s.charAt(r))
          r++;
        z[i] = r-- - l;
      } else if (z[i - l] < r - i + 1)
        z[i] = z[i - l];
      else {
        l = i;
        while (r < n && s.charAt(r - l) == s.charAt(r))
          r++;
        z[i] = r-- - l;
      }
    }
    return n + Arrays.stream(z).asLongStream().sum();
  }
}

import java.math.BigInteger;
import java.util.Scanner;
import java.util.stream.Stream;

public class Solution {

  static class NumberTree {
    final NumberTree[] childs = new NumberTree[10];
    short flags;

    public void add(final String numberString, final int i) {
      final int index = numberString.charAt(i) - '0';

      if (numberString.length() == i + 1) {
        this.flags |= 1 << index;
        return;
      }

      if (this.childs[index] == null) {
        this.childs[index] = new NumberTree();
      }
      this.childs[index].add(numberString, i + 1);
    }

    public int count(final String numberString, final int i) {
      final int index = numberString.charAt(i) - '0';
      final int count = (this.flags & (1 << index)) > 0 ? 1 : 0;

      if (this.childs[index] == null || numberString.length() == i + 1) {
        return count;
      }

      return count + this.childs[index].count(numberString, i + 1);
    }
  }

  static final NumberTree ROOT = new NumberTree();

  public static void main(final String[] args) {
    BigInteger bi = BigInteger.ONE;
    for (int i = 0; i < 801; i++) {
      ROOT.add(bi.toString(), 0);
      bi = bi.multiply(BigInteger.valueOf(2));
    }

    try (final Scanner scanner = new Scanner(System.in)) {
      final int t = Integer.parseInt(scanner.nextLine());
      Stream.generate(scanner::nextLine).limit(t).mapToInt(Solution::twoTwo).forEach(System.out::println);
    }
  }

  static int twoTwo(final String a) {
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
      count += ROOT.count(a, i);
    }
    return count;
  }
}

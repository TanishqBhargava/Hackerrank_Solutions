import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {

  static class MyBitSet {
    private final static int ADDRESS_BITS_PER_WORD = 6;
    private long[] words;
    private transient int wordsInUse = 0;

    private static int wordIndex(int bitIndex) {
      return bitIndex >> ADDRESS_BITS_PER_WORD;
    }

    public MyBitSet(int nbits) {
      words = new long[wordIndex(nbits - 1) + 1];
    }

    public void clear() {
      while (wordsInUse > 0)
        words[--wordsInUse] = 0;
    }

    public void set(int bitIndex) {
      int wordIndex = wordIndex(bitIndex);
      expandTo(wordIndex);
      words[wordIndex] |= (1L << bitIndex);
    }

    private void expandTo(int wordIndex) {
      int wordsRequired = wordIndex + 1;
      if (wordsInUse < wordsRequired) {
        wordsInUse = wordsRequired;
      }
    }

    public boolean get(int bitIndex) {
      int wordIndex = wordIndex(bitIndex);
      return (wordIndex < wordsInUse) && ((words[wordIndex] & (1L << bitIndex)) != 0);
    }
  }

  static int gcd(int x, int y) {
    if(x > y) {
      int temp = x;
      x = y;
      y = temp;
    }
    while (x > 0) {
       int z = x;
       x = y % x;
       y = z;
    }
    return y;
  }
  
  static MyBitSet bitSet;
  static final int K = 32;
  static final int M = 200000;
  static final int M_K = M / K;
  
  static int[] nextStep(int[] a, int n) {
    List<Integer> b = new ArrayList<>(n);
    bitSet.clear();
    bitSet.set(0);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int diff = Math.abs(a[j] - a[i]);
        if (!bitSet.get(diff)) {
          b.add(diff);
          bitSet.set(diff);
        }
      }
    }
    return b.stream()
        .mapToInt(Integer::intValue)
        .sorted()
        .toArray();
  }

  static int iterateIt(int[] b) {
    if (b.length > 49950) {
      return 49999;
    }

    int g = b[0];
    for (int x : b) {
      g = gcd(g, x);
    }
    if (g > 1) {
      for (int i = 0; i < b.length; i++) {
        b[i] /= g;
      }
    }

    long[] live = new long[M_K];
    for (int i = 0; i < b.length; i++) {
      for (int j = i + 1; j < b.length; j++) {
        int diff = b[j] - b[i] - 1;
        live[diff / K] |= 1L << ((long) (diff % K));
      }
    }

    int t = 2;
    int m = b[b.length - 1] - b[0];

    while (m > 0 && (live[0] & 1) == 0) {
      long[] liveN = new long[M_K];
      boolean bb = false;
      int m2 = m;
      for (int i = 0; i < m; i++) {
        int iDivK = i / K;
        int iModK = i % K;
        if (((live[iDivK] >>> (long) iModK) & 1) > 0) {
          if (!bb) {
            m2 = m - (i + 1);
          }
          bb = true;
          if (iModK < (K - 1)) {
            for (int j = iDivK; j < M_K; j++) {
              liveN[j - iDivK] |= live[j] >>> (long) (iModK + 1);
            }
          }
          for (int j = iDivK + 1; j < M_K; j++) {
            liveN[j - iDivK - 1] |= (live[j] << (long) (K - 1 - iModK));
          }
        }
      }
      live = liveN;
      m = m2;
      t++;
    }

    return t + m;
  }


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());

    int[] list = new int[n];
    int num = 0;
    bitSet = new MyBitSet(50001);

    boolean check = true;
    int last = 0;
    
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      int item = Integer.parseInt(st.nextToken());
      if (!bitSet.get(item)) {
        list[num++] = item;
        bitSet.set(item);
        if (last > 0 && item != last+1) {
          check = false;
        }
        last = item;
      }
    }
    
    int result = check || num == 1 
        ? num
        : iterateIt(nextStep(list, num));
    bw.write(String.valueOf(result));
    bw.newLine();

    bw.close();
    br.close();
  }
}

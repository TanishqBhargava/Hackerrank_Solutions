import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.sqrt;

public class Solution {

    static final Map<Integer, List<Integer>> squaresMap = new TreeMap<>();
    static final int[] squares = new int[68];
    static final int[] counts = new int[68];
    static final double[] roots = new double[300];

    static {
        Map<Integer, List<Integer>> localSquareMap = squaresMap;
        for (int x = 1; x <= 12; x++) {
            for (int y = 1; y <= 12; y++) {
                int sq = x * x + y * y;
                double distance = sqrt(sq);
                if (distance != (int) distance) {
                    List<Integer> list = localSquareMap.get(sq);
                    if (list == null) {
                        localSquareMap.put(sq, list = new ArrayList<>(3));
                    }
                    list.add(x * 16 + y);
                }
            }
        }

        int[] localSquares = squares;
        int index = 0;
        for (Map.Entry<Integer, List<Integer>> entry : localSquareMap.entrySet()) {
            localSquares[index] = entry.getKey();
            counts[index] = entry.getValue().size();
            roots[localSquares[index]] = sqrt(localSquares[index]);
            index++;
        }
    }

    static final long[] squaresSerialized = new long[942415];
    static final double[] distancesUnsorted = new double[squaresSerialized.length];
    static final double[] distancesSorted = new double[squaresSerialized.length];
    static int count = 0;

    static int privateCounter = 0;
    static void iter(int index, int number, int[] four) {
        if (number == 4) {
            int localCount = Solution.count;
            squaresSerialized[Solution.count] = serialize(four);
            double distance = getDistance(four);
            distancesUnsorted[Solution.count] = distancesSorted[Solution.count] = distance - (int) distance;
            Solution.count = localCount + 1;
        } else {
            int[] localSquares = Solution.squares;
            if (index == localSquares.length) return;
            int[] localCounts = Solution.counts;
            if (localCounts[index] != 0) {
                localCounts[index]--;
                four[number] = localSquares[index];
                iter(index, number + 1, four);
                localCounts[index]++;
            }
            iter(index + 1, number, four); // skip current number
        }
    }

    private static double getDistance(int[] four) {
        return roots[four[0]] + roots[four[1]] + roots[four[2]] + roots[four[3]];
    }

    private static long serialize(int[] four) {
        return (((long) four[0]) << 48) + (((long) four[1]) << 32)
             + (((long) four[2]) << 16) + (((long) four[3]));
    }

    static int originalX;
    static int originalY;

    static void solve(int index, int number, int[] four) {
        if (number == 4) {
            if (privateCounter++ % 7 != 0) return;
            double originalDistance = getDistance(four);
            for (int k = count - 1; k >= 0; k -= 31) {
                double candidateDistance = distancesSorted[k];
                double distanceToSearch = originalDistance + candidateDistance;
                distanceToSearch -= (int) distanceToSearch;
                distanceToSearch = 1 - distanceToSearch;
                int i = Arrays.binarySearch(distancesSorted, 0, count, distanceToSearch);
                if (i >= 0) {
                    double result = originalDistance + candidateDistance + distancesSorted[i];
                    result -= (int) result;
                    if (result < 1e-12 || result > (1 - 1e-12)) {
                        printAnswer(four, distancesSorted[k], distancesSorted[i]);
                    }
                } else {
                    i = -1 - i;

                    if (i < count) {
                        double result = originalDistance + candidateDistance + distancesSorted[i];
                        result -= (int) result;
                        if (result < 1e-12 || result > (1 - 1e-12)) {
                            printAnswer(four, distancesSorted[k], distancesSorted[i]);
                        }
                    }

                    if (i > 0) {
                        double result = originalDistance + candidateDistance + distancesSorted[i - 1];
                        result -= (int) result;
                        if (result < 1e-12 || result > (1 - 1e-12)) {
                            printAnswer(four, distancesSorted[k], distancesSorted[i - 1]);
                        }
                    }
                }
            }
        } else {
            if (index == squares.length) return;
            solve(index + 1, number, four); // skip current number
            if (counts[index] != 0) {
                counts[index]--;
                four[number] = squares[index];
                solve(index, number + 1, four);
                counts[index]++;
            }
        }
    }

    private static final List<String> result = new ArrayList<>(12);
    private static void printAnswer(int[] original, double candidateDistance, double distance) {
        result.add(originalX + " " + originalY);
        addToResult(original[1]);
        addToResult(original[2]);
        addToResult(original[3]);


        for (int i = 0; i < count; i++) {
            if (Math.abs(distancesUnsorted[i] - candidateDistance) < 1e-13) {
                long four = squaresSerialized[i];
                addToResult((int) ((four >>> 48) & 0xFFFF));
                addToResult((int) ((four >>> 32) & 0xFFFF));
                addToResult((int) ((four >>> 16) & 0xFFFF));
                addToResult((int) (four & 0xFFFF));
                break;
            }
        }

        for (int i = 0; i < count; i++) {
            if (Math.abs(distancesUnsorted[i] - distance) < 1e-13) {
                long four = squaresSerialized[i];
                addToResult((int) ((four >>> 48) & 0xFFFF));
                addToResult((int) ((four >>> 32) & 0xFFFF));
                addToResult((int) ((four >>> 16) & 0xFFFF));
                addToResult((int) (four & 0xFFFF));
                break;
            }
        }
        for (String s : result.subList(1, result.size())) {
            System.out.println(s);
        }

        System.out.flush();
        System.exit(1);
    }

    private static void addToResult(int square) {
        for (int pair : squaresMap.get(square)) {
            int x = pair / 16;
            int y = pair % 16;

            String s = x + " " + y;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }
            s = y + " " + x;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }

            x = -x;
            s = x + " " + y;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }
            s = y + " " + x;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }

            y = -y;
            s = x + " " + y;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }
            s = y + " " + x;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }

            x = -x;
            s = x + " " + y;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }
            s = y + " " + x;
            if (!result.contains(s)) {
                result.add(s);
                return;
            }
        }
    }

    public static void main(String[] args) {
        iter(0, 0, new int[4]);
        Arrays.sort(distancesSorted, 0, count);

        originalX = readInt();
        originalY = readInt();

        int square = originalX * originalX + originalY * originalY;
        int[] four = new int[4];
        four[0] = square;
        counts[Arrays.binarySearch(squares, square)] = 0;
        solve(0, 1, four);
    }

    private static int readInt() {
        try {
            int c = in.read();
            while (c <= 32) {
                c = in.read();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = in.read();
            }
            int result = (c - '0');
            c = in.read();
            while (c >= '0') {
                result = result * 10 + (c - '0');
                c = in.read();
            }
            return minus ? -result : result;
        } catch (IOException e) {
            return -1; // should not happen
        }
    }

    private static long readLong() {
        try {
            int c = in.read();
            while (c <= 32) {
                c = in.read();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = in.read();
            }
            long result = (c - '0');
            c = in.read();
            while (c >= '0') {
                result = result * 10 + (c - '0');
                c = in.read();
            }
            return minus ? -result : result;
        } catch (IOException e) {
            return -1; // should not happen
        }
    }

    private static double readDouble() {
        return Double.parseDouble(readWord(SMALL_CHAR_BUFFER));
    }

    private static String readWord(char[] buffer) {
        try {
            int c = in.read();
            while (c <= 32) {
                c = in.read();
            }
            int length = 0;
            while (c > 32) {
                buffer[length] = (char) c;
                c = in.read();
                length++;
            }
            return String.valueOf(buffer, 0, length);
        } catch (IOException ex) {
            throw new RuntimeException(ex); // should not happen
        }
    }

    private static String readLine(char[] buffer) {
        try {
            int c = in.read();
            while (c <= 32) {
                c = in.read();
            }
            int length = 0;
            while (c != '\n' && c != '\r' && c != -1) {
                buffer[length] = (char) c;
                c = in.read();
                length++;
            }
            return String.valueOf(buffer, 0, length);
        } catch (IOException ex) {
            throw new RuntimeException(ex); // should not happen
        }
    }

    private static InputStream in = new BufferedInputStream(System.in);
    private static final char[] SMALL_CHAR_BUFFER = new char[32];
}

import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            b[i + 1] = b[i] ^ x;
        }
        
        int[] c = new int[n + 2];
        for (int i = 0; i < n + 1; i++) {
            c[i + 1] = c[i] + b[i];
        }
        
        while (q-- > 0) {
            int x = nextInt();
            int y = nextInt();
            int k = nextInt();
            
            int len = y - x + 2;
            
            int ones;
            
            if (k == 0) {
                ones = c[y + 2] - c[x];
                
            } else {
                ones = len / 2;
            }
            out.println((long)ones * (len - ones));
        }
    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}

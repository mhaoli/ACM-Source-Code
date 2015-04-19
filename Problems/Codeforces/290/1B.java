import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        public void run() {
                int n = reader.nextInt();
                int[] a = new int[n];
                int[] c = new int[n];
                for(int i = 0; i < n; ++i) a[i] = reader.nextInt();
                for(int i = 0; i < n; ++i) c[i] = reader.nextInt();

                int ans = Integer.MAX_VALUE;
                int[] state = new int[n];
                int[][] dp = new int[n][1<<10];
                ArrayList<Integer> fac = new ArrayList<Integer>();
                for(int i = 0; i < n; ++i) {
                        init(a[i], fac);
                        ans = Math.min(ans, solve(i, a, c, fac, dp, state));
                }
                if(ans == Integer.MAX_VALUE) ans = -1;
                writer.println(ans);
                writer.close();
        }

        void init(int n, ArrayList<Integer> fac) {
                fac.clear();
                for(int i = 2; i * i <= n; ++i) if(n % i == 0){
                        fac.add(i);
                        while(n % i == 0) n /= i;
                }
                if(n > 1) fac.add(n);
        }
        
        int solve(int p, int[] a, int[] c, ArrayList<Integer> fac, int[][] dp, int[] state) {
                if(fac.isEmpty()) return c[p];
                if(p == 0) return Integer.MAX_VALUE;
                int n = fac.size(), up = (1 << n) - 1, ret = Integer.MAX_VALUE;
                for(int i = 0, j; i < p; ++i) for(j = 0; j < (1<<n); ++j) dp[i][j] = Integer.MAX_VALUE;
                dp[0][0] = 0;
                for(int i = 0, j; i < p; ++i) {
                        state[i] = j = 0;
                        for(int t : fac) {
                                if(a[i] % t != 0) state[i] |= 1 << j;
                                ++j;
                        }
                        if(i == 0 && state[i] != 0) dp[0][state[i]] = c[0];
                }

                ret = Math.min(ret, dp[0][up]);

                for(int i = 1, j; i < p; ++i) {
                        for(j = 0; j < up; ++j) if(dp[i-1][j] != Integer.MAX_VALUE){
                                dp[i][j] = Math.min(dp[i-1][j], dp[i][j]);
                                dp[i][j|state[i]] = Math.min(dp[i-1][j] + c[i], dp[i][j|state[i]]);
                        }
                        ret = Math.min(ret, dp[i][up]);
                }
                if(ret != Integer.MAX_VALUE) ret += c[p];
                //writer.println(p + " " + ret);
                return ret;
        }
        
        void out(int a) {
                writer.println(a);
        }

        Main() {
                //try {
                        reader = new InputReader(System.in);
                        writer = new PrintWriter(System.out);
                        //reader = new InputReader(new FileInputStream("tst.in"));
                        //writer = new PrintWriter(new File("tst.out"));
                //} catch(FileNotFoundException ex) {
                //}
        }

        public static void main(String[] args) {
                new Main().run();
        }

        private static void debug(Object...os) {
                System.err.println(Arrays.deepToString(os));
        }

        private InputReader reader;
        private PrintWriter writer;
}

class InputReader {
        public InputReader(InputStream stream) {
                this.stream = stream;
        }

        public int nextChar() {
                if (charCount == -1)
                        throw new InputMismatchException();
                if (head >= charCount) {
                        head = 0;
                        try {
                                charCount = stream.read(buffer);
                        } catch (IOException e) {
                                throw new InputMismatchException();
                        }
                        if (charCount <= 0) return -1;
                }
                return buffer[head ++];
        }

        public String nextStr() {
                int c = nextChar();
                while (isSpaceChar(c)) {
                        c = nextChar();
                }
                String ret = new String();
                do {
                        ret += (char)c;
                        c = nextChar();
                } while(!isSpaceChar(c));
                return ret;
        }

        public int nextInt() {
                int c = nextChar();
                while (isSpaceChar(c)) {
                        c = nextChar();
                }
                int sign = 1;
                if (c == '-') {
                        sign = -1;
                        c = nextChar();
                }
                int result = 0;
                do {
                        if (c < '0' || c > '9') {
                                throw new InputMismatchException();
                        }
                        result *= 10;
                        result += c - '0';
                        c = nextChar();
                } while (!isSpaceChar(c));
                return sign * result;
        }

        public boolean isSpaceChar(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private InputStream stream;
        private int head, charCount;
        private byte[] buffer = new byte[1024];
}

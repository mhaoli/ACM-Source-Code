import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        int[] an;
        long[] fac;
        long[] inv;
        long[] inv_fac;
        long mod = (long)1e9 + 7;
        int add(int a, int b) {
                a += b; if(a >= mod) a -= mod;
                return a;
        }
        int add(int a, long b) {
                return add(a, (int)b);
        }
        int pow_mod(long p, long n) {
                long ret = 1;
                for(; n > 0; n >>= 1) {
                        if(n % 2 == 1) ret = ret * p % mod;
                        p = p * p % mod;
                }
                return (int)ret;
        }
        long C(int m, int n) {
                long ret = fac[n];
                ret = ret * inv_fac[n-m] % mod;
                ret = ret * inv_fac[m] % mod;
                //ret = ret * pow_mod(fac[n-m], mod - 2) % mod;
                //ret = ret * pow_mod(fac[m], mod - 2) % mod;
                return ret;
        }
        void init(int n) {
                fac = new long[n+1];
                inv = new long[n+1];
                inv_fac = new long[n+1];
                inv_fac[0] = 1;
                inv_fac[1] = inv[1] = fac[1] = fac[0] = 1;
                for (int t, k, i = 2; i <= n; ++ i){
                        t = (int)mod / i; k = (int)mod - t * i; 
                        inv[i] = ((long)i * t % mod) * t % mod;
                        inv[i] = ((long)inv[i] * inv[k] % mod) * inv[k] % mod;

                        fac[i] = fac[i-1] * i % mod;
                        inv_fac[i] = inv_fac[i-1] * inv[i] % mod;
                }
        }
        public void run() {
                int n = reader.nextInt(), k = reader.nextInt(), sum = 0, ans = 0;
                init(n);
                String str = reader.nextStr();
                an = new int[n];
                for(int i = 0; i < n; ++i) sum += (an[i] =  str.charAt(i) - '0');
                long ten = 1;
                for(int i = n-1; i >= 0 && sum > 0 && i >= k; --i, ten = ten * 10 % mod) {
                        sum -= an[i];
                        ans = add(ans, an[i] * ten % mod * C(k, i) % mod);
                        if(i > 0 && k > 0) ans = add(ans, sum * ten % mod * C(k-1, i-1) % mod);
                }
                writer.println(ans);
                writer.close();
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
                StringBuilder ret = new StringBuilder();
                do {
                        ret.append((char)c);
                        c = nextChar();
                } while(!isSpaceChar(c));
                return ret.toString();
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

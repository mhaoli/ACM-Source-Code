import java.math.*;
import java.util.*;
import java.io.*;

public class C{
    long mod;

    class oo{
        BigInteger a;
        long b;
        public oo(long x){
            a = BigInteger.valueOf (x / mod);
            b = x % mod;
        }
        public oo(BigInteger a, long b){
            this.a = a; this.b = b;
        }
        public oo addIt (oo x){
            a = a.add (x.a);
            b += x.b;
            if (b >= mod){
                b -= mod;
                a = a.add (BigInteger.ONE);
            }
            return this;
        }
        public oo add (oo x){
            return new oo (a, b).addIt (x);
        }
        public oo mul (long n){
            oo res = new oo(0);
            oo t = new oo (a, b);
            for (long i = n; i > 0; i >>= 1){
                if ((i & 1) == 1) res.addIt (t);
                t.addIt (t);
            }
            return res;
        }
        int compareTo (long t){
            return a.compareTo (BigInteger.valueOf (t));
        }
    }

    oo[] ten;

    InputReader re = new InputReader(System.in);
    PrintWriter wr = new PrintWriter(System.out);

    public oo getF (long m){
        long tmp = 1;
        int pos = 0, sum = 0;
        int[] dig = new int[20];
        for (long i = m; i > 0; i /= 10){
            dig[pos++] = (int)(i % 10);
            if (i < m) tmp *= 10;
        }

        oo res = new oo(0);
        for (int i = pos-1; i >= 0; -- i){
            res.addIt (new oo (dig[i] * (1 + m % tmp)));
            res.addIt (ten[i].mul (dig[i] * (dig[i]-1) / 2));
            long t = m / tmp / 10;
            res.addIt (ten[i].mul (t).mul (45));

            sum += dig[i];
            tmp /= 10;
        }
        return res;
    }
    
    public void main (){
        mod = re.nextLong ();
        long[] last = new long[19*9];
        Arrays.fill (last, -1);

        ten = new oo[19];
        ten[0] = new oo (1);
        for (int i = 1; i < 19; ++ i)
            ten[i] = ten[i-1].mul (10);

        long cnt = 0;
        while (true){
            long l = 1, r = (long)4e18, res = 1;
            for (long m; l <= r; ){
                m = (l + r) >> 1;
                if (getF (m).compareTo (cnt) >= 0){
                    res = m; r = m - 1;
                } else l = m + 1;
            }
            int t = (int)getF(res).b;
            if (last[t] == -1) last[t] = res;
            else if (last[t] != res){
                wr.printf ("%d %d\n", last[t] + 1, res);
                break;
            }
            ++ cnt;
        }

        wr.close ();
    }

    public static void main(String[] args) {
        new C().main ();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream in){
        reader = new BufferedReader(new InputStreamReader(in), 32768);
        tokenizer = new StringTokenizer("");
    }

    public String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
        return Long.parseLong(next());
    }
}


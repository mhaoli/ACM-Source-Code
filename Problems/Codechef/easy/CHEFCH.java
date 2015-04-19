import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        public void run() {
                int _ = reader.nextInt();
                for(int n; _-- != 0; ) {
                        String s = reader.nextStr();
                        String[] tmp = new String[2];
                        for(int i = 0; i < 2; ++i) tmp[i] = new String();
                        n = s.length();
                        for(int i = 0, j = 0; i < n; ++i, j ^= 1) {
                                tmp[j] += '+';
                                tmp[j^1] += '-';
                        }
                        int ans = Integer.MAX_VALUE;
                        for(int t = 0, i, j, cnt; t < 2; ++t) {
                                cnt = 0;
                                for(i = 0; i < n; ++i) {
                                        if(s.charAt(i) != tmp[t].charAt(i)) ++cnt;
                                }
                                ans = Math.min(ans, cnt);
                        }
                        writer.println(ans);
                }
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

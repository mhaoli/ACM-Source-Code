import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        public void run() {
                int n = reader.nextInt();
                String[] str = new String[n];
                for(int i = 0; i < n; ++i) {
                        str[i] = reader.nextStr();
                }

                ArrayList<Integer>[] E = new ArrayList[26];
                for(int i = 0; i < 26; ++i) E[i] = new ArrayList<Integer>();

                boolean ans_u = false;
                char t1, t2;
                for(int i = 0, j, k; i < n-1; ++i) {
                        for(j = k = 0; j < str[i].length() && k < str[i+1].length(); ++j, ++k) {
                                t1 = str[i].charAt(j);
                                t2 = str[i+1].charAt(k);
                                if(t1 == t2) continue;
                                else {
                                        E[(int)(t1-'a')].add((int)(t2 - 'a')); break;
                                }
                        }
                        if(j == str[i].length() || k == str[i+1].length()) {
                                if(str[i].length() > str[i+1].length()) ans_u = true;
                        }
                }
                if(ans_u) writer.println("Impossible");
                else solve(E);
                writer.close();
        }
        void solve(ArrayList<Integer>[] E) {
                LinkedList<Integer> Q = new LinkedList<Integer>();
                int[] cnt = new int[26];
                String res = new String();
                for(int i = 0; i < 26; ++i) {
                        for(int j : E[i]) ++cnt[j];
                }
                for(int i = 0; i < 26; ++i) if(cnt[i] == 0) Q.add(i);

                int x;
                while(!Q.isEmpty()) {
                        x = Q.getFirst(); Q.removeFirst();
                        res += (char)(x + 'a');
                        for(int i : E[x]) {
                                if(--cnt[i] == 0) Q.add(i);
                        }
                }
                if(res.length() == 26) writer.println(res);
                else writer.println("Impossible");
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

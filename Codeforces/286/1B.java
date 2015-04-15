import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        public static int[] cnt = new int[100009];
        public void run() {
                int n = reader.nextInt(), m = reader.nextInt();
                ArrayList<Integer>[] E = new ArrayList[n];
                for(int i = 0; i < n; ++i) E[i] = new ArrayList<Integer>();
                int[] f = new int[n];
                for(int i = 0; i < n; ++i) f[i] = i;

                for(int i = 0, u, v; i < m; ++i) {
                        u = reader.nextInt() - 1;
                        v = reader.nextInt() - 1;
                        E[u].add(v); 
                        if(find(u, f) != find(v, f)) f[find(u, f)] = find(v, f);
                }

                ArrayList<Integer>[] son = new ArrayList[n];
                for(int i = 0; i < n; ++i) son[i] = new ArrayList<Integer>();
                for(int i = 0; i < n; ++i) {
                        son[find(i, f)].add(i);
                }

                int ans = 0;
                for(int i = 0; i < n; ++i) if(find(i, f) == i){
                        if(check(n, i, son[i], E)) --ans;
                        ans += son[i].size();
                }
                writer.println(ans);
                writer.close();
        }

        int find(int x, int[] f) {
                if(x == f[x]) return f[x];
                return f[x] = find(f[x], f);
        }

        boolean check(int N, int x, ArrayList<Integer> A, ArrayList<Integer>[] E) {
                int n = A.size(), num = 0;
                for(int i : A) cnt[i] = 0;
                LinkedList<Integer> Q = new LinkedList();
                for(int i : A) for(int j : E[i]) ++cnt[j];
                for(int i : A) if(cnt[i] == 0) {
                        ++num; Q.add(i);
                }
                while(!Q.isEmpty()) {
                        int u = Q.getFirst(); Q.removeFirst();
                        for(int i : E[u]) {
                                --cnt[i];
                                if(cnt[i] == 0) {
                                        ++num;
                                        Q.add(i);
                                }
                        }
                        if(num == n) return true;
                }
                return num == n;
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

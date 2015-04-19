import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
        static int Dx[] = {-1, 1, 0, 0}, Dy[] = {0, 0, -1, 1};
        int n, m, top;
        boolean[][] board;
        boolean[][] vis;
        String[] ans;
        public void run() {
                n = reader.nextInt();
                m = reader.nextInt();
                board = new boolean[n][m];
                vis = new boolean[n][m];
                ans = new String[n*m*3];
                for(int i = 0, j; i < n; ++i) for(j = 0; j < m; ++j) 
                        board[i][j] = vis[i][j] = false;
                String tmp = new String();
                for(int i = 0, j; i < n; ++i) {
                        tmp = reader.nextStr();
                        for(j = 0; j < m; ++j) if(tmp.charAt(j) == '.') board[i][j] = true;
                }
                top = 0;
                for(int i = 0, j; i < n; ++i) {
                        for(j = 0; j < m; ++j) if(posin(i, j))
                                dfs(i, j, false);
                }
                writer.println(top);
                for(int i = 0; i < top; ++i) writer.println(ans[i]);
                writer.close();
        }

        boolean posin(int x, int y) {
                if(x < 0 || x >= n || y < 0 || y >= m) return false;
                return !vis[x][y] && board[x][y];
        }

        void dfs(int x, int y, boolean flag) {
                ans[top++] = "B " + (x+1) + " " + (y+1);
                vis[x][y] = true;
                for(int d = 0; d < 4; ++d)
                        if(posin(x + Dx[d], y + Dy[d])) {
                                dfs(x + Dx[d], y + Dy[d], true);
                        }
                if(flag){
                        ans[top++] = "D " + (x+1) + " " + (y+1);
                        ans[top++] = "R " + (x+1) + " " + (y+1);
                }
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

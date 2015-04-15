import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
       public void run() {
               int n = reader.nextInt(), d = reader.nextInt(), up = 30000;
               int[][] dp = new int[up+1][600];
               int[] vis = new int[up+1];
               for(int i = 0, tmp; i < n; ++i) {
                       tmp = reader.nextInt();
                       ++vis[tmp];
               }
               for(int i = 0, j; i <= up; ++i)
                       for(j = 0; j < 600; ++j) dp[i][j] = -1;
               dp[d][300] = vis[d];
               int ans = 0;
               for(int i = d, j, k; i < up; ++i) {
                       for(j = 0; j < 600; ++j) if(dp[i][j] != -1){
                               for(k = Math.max(j + d - 301, 1); k <= Math.min(j + d - 299, d + 299); ++k)
                                       if(k + i <= up) dp[k+i][k+300-d] = Math.max(dp[k+i][k+300-d], dp[i][j] + vis[k+i]);
                                       else ans = Math.max(ans, dp[i][j]);
                       }
               }
               for(int i = 0; i < 600; ++i) ans = Math.max(ans, dp[up][i]);
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

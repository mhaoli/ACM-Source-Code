import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

        public static void main(String[] args) {
                Scanner cin = new Scanner(System.in);
                while(cin.hasNext()) {
                        //String s = cin.next();
                        int n = cin.nextInt();
                        BigInteger ans, t1, t2;
                        for(int i = 0; i < n; ++i) {
                                t1 = cin.nextBigInteger(); 
                                t2 = cin.nextBigInteger(); 
                                ans = t1.add(t2);
                                System.out.println(ans.toString());
                        }
                }
                cin.close();
        }
}


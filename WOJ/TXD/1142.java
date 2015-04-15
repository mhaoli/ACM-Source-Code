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
                        BigInteger one = BigInteger.ONE, two = BigInteger.valueOf(2), ans = BigInteger.valueOf(1);
                        for(int i = 0; i < n; ++i) {
                                ans = ans.multiply(two).add(one);
                        }
                        System.out.println(ans.toString());
                }
                cin.close();
        }
}


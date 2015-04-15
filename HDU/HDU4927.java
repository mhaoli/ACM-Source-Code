import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
		for (int tt = 0; tt < T; ++ tt){
			//String s = cin.next();
            int n = cin.nextInt();
			BigInteger[] a = new BigInteger[3005];
            //if (n == 1){
			    //System.out.println(a[0].toString()); continue;
            //}
            for (int i = 0; i < n; ++ i) a[i] = cin.nextBigInteger();
            BigInteger c = BigInteger.ONE;
            BigInteger ans = BigInteger.ZERO;
            int t = 1;
            for (int i = 0; i < n; ++ i){
                BigInteger tmp = c.multiply (a[n - 1 - i]);
                c = c.multiply (BigInteger.valueOf (n - 1 - i));
                c = c.divide (BigInteger.valueOf (i + 1));
                if (t == 1){
                    ans = ans.add (tmp); t = -1;
                }
                else{
                    ans = ans.subtract (tmp); t = 1;
                }
            }
			System.out.println(ans.toString());
		}
		cin.close();
	}
}

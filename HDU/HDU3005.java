import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
        BigInteger one = BigInteger.ONE;
        BigInteger two = new BigInteger ("2");

        BigInteger t1 = new BigInteger ("23");
        BigInteger t2 = new BigInteger ("44");
        BigInteger t3 = new BigInteger ("12");

        BigInteger ans1[] = new BigInteger[102];
        BigInteger ans2[] = new BigInteger[102];
        ans1[0] = two; ans2[0] = one;
        for (int i = 1; i <= 100; ++ i){
            ans1[i] = ans1[i-1].multiply (t1);
            ans1[i] = ans1[i].add (ans2[i-1].multiply (t2));
            
            ans2[i] = ans1[i-1].multiply (t3);
            ans2[i] = ans2[i].add (ans2[i-1].multiply (t1));
        }
		while(cin.hasNext()) {
			//String s = cin.next();
            int n = cin.nextInt ();
            if (n == 0) break;
            BigInteger a = ans2[n];
            BigInteger b = ans1[n].subtract (a.add (one));
            b = b.divide (two);
			System.out.println(a.toString() + " " + b.toString());
		}
		cin.close();
	}
}


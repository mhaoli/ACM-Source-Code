import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
        int T = cin.nextInt (), cas = 1;
        BigInteger one = BigInteger.valueOf (2);
		while(cin.hasNext()) {
			//String s = cin.next();
			BigInteger x = cin.nextBigInteger(2);
			BigInteger y = cin.nextBigInteger(2);
            BigInteger res = x.gcd (y);
			System.out.println("Case #" + cas + ": " + res.toString(2));
            ++ cas;
		}
		cin.close();
	}
}


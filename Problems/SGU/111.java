import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			//String s = cin.next();
			BigInteger x = cin.nextBigInteger();
			BigInteger l = new BigInteger("1");
			BigInteger r = x.add(BigInteger.ZERO);
            BigInteger ans = new BigInteger("1");
            while (l.compareTo(r) <= 0){
                BigInteger m = l.add(r); m = m.divide(BigInteger.valueOf(2));
                if ((m.multiply(m)).compareTo(x) <= 0){
                    ans = m;
                    l = m.add (BigInteger.valueOf(1));
                }
                else r = m.subtract (BigInteger.valueOf(1));
            }
			System.out.println(ans.toString());
		}
		cin.close();
	}
}

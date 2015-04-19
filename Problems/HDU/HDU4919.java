import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
        BigInteger one = BigInteger.valueOf (1);
        BigInteger two = BigInteger.valueOf (2);

		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			BigInteger n = cin.nextBigInteger();

            if (n.compareTo (two) == 0){
			    System.out.println("0"); continue;
            }

            BigInteger ans = BigInteger.valueOf (0);
            BigInteger ji[] = n.divideAndRemainder (two);

            if (ji[1].compareTo (one) == 0){
                ans = ans.add (n.divide (two));
                ans = ans.add (one);
            }

            BigInteger sta = BigInteger.valueOf (4);
            while (true){
                BigInteger[] t = n.divideAndRemainder (sta);
                BigInteger tmp = (t[1].add (one)).subtract (sta.divide(two));
                tmp = tmp.abs();
                if ((t[1].add(one)).compareTo (sta.divide (two)) < 0){
                    ans = ans.subtract ( ((sta.divide(two)).subtract (t[1].add(one))).multiply (sta.divide(two)) );
                }
                ans = ans.add ((tmp.multiply (t[0].add (one))).multiply (sta.divide (two)));
                if (sta.compareTo (n) == 1) break;
                sta = sta.multiply (two);
            }

            ans = ans.subtract (n);

            ans = ans.multiply (two);
			System.out.println(ans.toString());
		}
		cin.close();
	}
}

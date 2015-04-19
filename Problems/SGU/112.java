import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			int a = cin.nextInt();
			int b = cin.nextInt();
			BigInteger x = BigInteger.valueOf(a);
			BigInteger y = BigInteger.valueOf(b);
			x = x.pow(b);
			y = y.pow(a);
			BigInteger ans = x.subtract(y);
			System.out.println(ans.toString());
		}
		cin.close();
	}
}

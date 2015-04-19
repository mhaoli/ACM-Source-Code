import java.math.BigInteger;
import java.util.Scanner;

public class Solution{

	public static void main(String[] args) {
        BigInteger TWO = BigInteger.valueOf(2);
		Scanner cin = new Scanner(System.in);
        while(cin.hasNext()) {
            BigInteger a = cin.nextBigInteger();
            BigInteger yu = a.mod (TWO);
            BigInteger ans = a.subtract (BigInteger.ONE);
            ans = ans.divide (TWO);
            if (yu == BigInteger.ZERO){
                if (ans.mod (TWO) == BigInteger.ZERO)
                    ans = ans.subtract (BigInteger.ONE);
            }
            System.out.println(ans.toString());
        }
		cin.close();
	}
}


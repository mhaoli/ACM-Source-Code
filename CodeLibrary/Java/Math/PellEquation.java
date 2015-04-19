import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

    static BigInteger one = BigInteger.ONE;
    static BigInteger zero = BigInteger.ZERO;
    static BigInteger two = new BigInteger ("2");

    static class Pell{
        BigInteger x, y;
        boolean ok;
        void solve (int D){
            int sqrtD = (int)Math.sqrt ((double)D);
            if (sqrtD * sqrtD == D){
                ok = false; return;
            } else ok = true;
            BigInteger n = BigInteger.valueOf (D);
            BigInteger ds = BigInteger.valueOf (sqrtD);
            BigInteger c = ds;
            BigInteger q = n.subtract(c.pow(2));
            BigInteger a = c.add (ds).divide (q);
            int step = 0;
            BigInteger X[] = {one, ds};
            BigInteger Y[] = {zero, one};
            while (true){
                X[step] = a.multiply (X[step^1]).add(X[step]);
                Y[step] = a.multiply (Y[step^1]).add(Y[step]);
                c = a.multiply(q).subtract(c);
                q = n.subtract(c.pow(2)).divide(q);
                a = ds.add(c).divide(q);
                step ^= 1;
                if (c.equals (ds) && q.equals(one) && step != 0) break;
            }
            x = X[0]; y = Y[0];
        }
    }
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
        int D;
		while((D = cin.nextInt()) != 0) {
            Pell pell = new Pell();
            pell.solve (D);
            if (pell.ok){
                BigInteger X = pell.x, Y = pell.y;
                System.out.println (X + " " + pell.y);
            } else System.out.println("Impossible!");
		}
		cin.close();
	}
}


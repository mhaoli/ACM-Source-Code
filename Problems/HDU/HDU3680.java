import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main{
    static BigInteger t0 = BigInteger.ZERO;
    static BigInteger t1 = BigInteger.ONE;
    static BigInteger t2 = new BigInteger("2");

    public static int ask_len (BigInteger n){
        int res = 0;
        while (n.compareTo (t0) != 0){
            ++ res; n = n.divide (t2);
        }
        return res;
    }

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);

        BigInteger inf = t1;
        for (int i = 1; i < 2222; ++ i)
            inf = inf.multiply (t2);

		while(cin.hasNext()){
			BigInteger n = cin.nextBigInteger ();
			BigInteger m = cin.nextBigInteger ();
            BigInteger tn, tm;

            if (n.compareTo (t0) == 0 && m.compareTo (t0) == 0) break;

            BigInteger pre[] = new BigInteger[3000];
            BigInteger d[][] = new BigInteger[3000][5];
            
            tn = n;
            int ln = ask_len (tn), ln_tmp = ln;

            for (int i = 0; i <= ln + 1; ++ i){
                d[i][0] = inf; d[i][1] = inf;
            }

            tn = n;
            while (ln_tmp > 0){
                pre[ln_tmp] = tn;
                d[ln_tmp][0] = (tn.subtract (m)).abs ();
                d[ln_tmp][1] = ((tn.add (t1)).subtract (m)).abs ();

                tn = tn.divide (t2); -- ln_tmp;
            }

            for (int i = 2; i <= ln; ++ i){
                boolean flag = true;
                if (pre[i].compareTo (pre[i-1].multiply (t2)) == 0) flag = false;

                if (flag){
                    if (d[i][0].compareTo (d[i-1][0].add (t2)) > 0) 
                        d[i][0] = d[i-1][0].add (t2);
                    if (d[i][0].compareTo (d[i-1][1].add (t2)) > 0)
                        d[i][0] = d[i-1][1].add (t2);

                    if (d[i][1].compareTo (d[i-1][0].add (t2)) > 0)
                        d[i][1] = d[i-1][0].add (t2);
                    if (d[i][1].compareTo (d[i-1][1].add (t1)) > 0)
                        d[i][1] = d[i-1][1].add (t1);
                }
                else{
                    if (d[i][0].compareTo (d[i-1][0].add (t1)) > 0)
                        d[i][0] = d[i-1][0].add (t1);
                    if (d[i][0].compareTo (d[i-1][1].add (t2)) > 0)
                        d[i][0] = d[i-1][1].add (t2);
                    
                    if (d[i][1].compareTo (d[i-1][0].add (t2)) > 0)
                        d[i][1] = d[i-1][0].add (t2);
                    if (d[i][1].compareTo (d[i-1][1].add (t2)) > 0)
                        d[i][1] = d[i-1][1].add (t2);
                }
            }

            //for (int i = 1; i <= ln; ++ i){
			    //System.out.println(pre[i]);
			    //System.out.println(d[i][0] + " " + d[i][1]);
            //}
//
			System.out.println(d[ln][0]);
		}
		cin.close();
	}
}

import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) {
        BigInteger[] an = new BigInteger[99*99];
        int cnt = 0; 
        for (int i = 2; i <= 100; ++ i){
            BigInteger t = BigInteger.valueOf (i);
            BigInteger tmp = t;
            for (int j = 2; j <= 100; ++ j){
                tmp = tmp.multiply (t);
                an[cnt++] = tmp;
            }
        }
        Arrays.sort (an);
        int ans = 1;
        for (int i = 1; i < cnt; ++ i)
            if (an[i].compareTo (an[i-1]) != 0) ++ ans;
        System.out.println(ans);
    }
}


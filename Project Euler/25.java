import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) {
        //String s = cin.next();
        BigInteger last = BigInteger.ONE;
        BigInteger now = last;
        BigInteger ten = new BigInteger("10");
        BigInteger up = now;
        for (int i = 1; i < 1000; ++ i) up = up.multiply (ten);

        int cnt = 2;
        while (now.compareTo (up) < 0){
            ++ cnt;
            BigInteger tmp = now.add (last);
            last = now; now = tmp;
        }
        System.out.println(cnt);
        //System.out.println(now.toString());
    }
}


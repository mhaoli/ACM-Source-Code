/*
 * Author:  Plumrain
 * Created Time:  2013-10-17 11:35
 * File Name: math-POJ-1095.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

int catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};

void gao(int n)
{
    if (!n) return ;

    int x, k;
    for (int i = 1;; ++ i)
        if (n > catalan[i])
            n -= catalan[i];
        else{
            k = i;
            break;
        }

    if (k == 1){
        printf ("X");
        return ;
    }

    for (int i = 0; i < k; ++ i)
        if (n - catalan[i]*catalan[k-1-i] > 0)
            n -= catalan[i] * catalan[k-1-i];
        else{
            x = i;
            break;
        }

    int ln = n / catalan[k-1-x] + (n%catalan[k-1-x] != 0);
    int rn = (n-1) % catalan[k-1-x] + 1;
    if (x){
        int tmp = 0;
        for (int j = 1; j < x; ++ j)
            tmp += catalan[j];
        printf ("(");
        gao(ln + tmp);
        printf (")"); 
    }
    printf ("X");
    if (k - 1 - x){
        int tmp = 0;
        for (int j = 1; j < k - 1 - x; ++ j)
            tmp += catalan[j];
        printf ("(");
        gao(rn + tmp);
        printf (")");
    }
}

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF && n){
        gao(n);
        printf ("\n");
    }
    return 0;
}

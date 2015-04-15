/*
 * Author:  Plumrain
 * Created Time:  2014-02-10 23:16
 * File Name: D.cpp
 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int gao(int n, double x)
{
    int a = (int)x - 1;
    for (int i = a; i < a + 5; ++ i){
        if ((i+2)*(n-i-1) < (i+1)*n) return i + 1;
    }
    return a + 1;
}

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        double del = sqrt(1.0 + 4*n), ans = (del - 1) / 2;
        printf ("%.2f %d\n", ans, gao(n, ans));
    }
    return 0;
}

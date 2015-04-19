/*
 * Author:  Plumrain
 * Created Time:  2013-11-12 18:35
 * File Name: DP-SGU-495.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        double x[2] = {1.0};
        for (int i = 2; i <= m; ++ i){
            x[1] = (x[0] + 1) * (n - x[0]) / n + x[0] * x[0] / n;
            x[0] = x[1];
        }
        if (m > 1)
            printf ("%.10f\n", x[1]);
        else
            printf ("%.10f\n", m ? 1.0 : 0.0 );
    }
    return 0;
}

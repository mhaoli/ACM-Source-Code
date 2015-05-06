/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 19.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl

int temp[7] = {1, 3, 5, 7, 8, 10, 12};
int Zeller(int Y, int m, int d)
{
    int c = Y / 100, y = Y % 100;
    if (m < 3) m += 12;
    int w = (c/4 - 2*c + y + y/4 + 13*m/5 + d - 1) % 7;
    if (w < 0) w += 7; 
    return w;
}
int main()
{
    int y = 1901, m = 1, d = 1, num = 0;
    while (y < 2001){
        if (d == 1 && Zeller(y, m, d) == 1) ++ num;
        ++ d;
        if (d == 31) d = 1, ++ m;
        else if (d == 30){
            bool u = 0;
            for (int i = 0; i < 7; ++ i) if (temp[i] == m) u = 1;
            if (!u) d = 1, ++ m;
        }
        else if (d == 29){
            if (m == 2) d = 1, ++ m;
        }
        else if (d == 28 && m == 2){
            if (y % 4 == 0) ++ m, d = 1;
        }

        if (m == 13) ++ y, m = 1;
    }
    out (num);
    return 0;
}

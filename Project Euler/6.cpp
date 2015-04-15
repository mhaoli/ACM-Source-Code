/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 6.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
int main()
{
    int64 x = 0, y = 0;
    for (int i = 1; i <= 100; ++ i)
        x += i*i, y += i;
    out (x); out (y);
    out (y*y - x);
    return 0;
}

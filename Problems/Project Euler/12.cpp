/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 12.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
bool ok(int64 x)
{
    int num = 0;
    for (int64 i = 1; i*i <= x; ++ i) if (x % i == 0){
        num += 2;
        if (i == x/i) -- num;
        if (num > 500) return 1;
    }
    return 0;
}
int main()
{
    int64 x = 0;
    for (int i = 1; i < 1000005; ++ i){
        x += i;
        if (ok(x)){
            out (x); break;
        }
    }
    return 0;
}

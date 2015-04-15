/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 9.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl

bool ok(int a, int b, int c)
{
    if (a*a + b*b == c*c) return 1;
    return 0;
}
int main()
{
    int ans = 0;
    for (int i = 0; i <= 292; ++ i){
        for (int j = i; j < 1000; ++ j){
            if (ok(i, j, 1000-i-j)){
                ans = i * j * (1000-i-j);
                break;
            }
        }
        if (ans) break;
    }
    out (ans);
    return 0;
}

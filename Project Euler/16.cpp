/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 16.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
struct big{
    int len, dit[10000];
    void clear(){
        len = 0; clr0 (dit);
    }
    void operator* (int x){
        for (int i = 0; i < len; ++ i){
            dit[i] *= 2;
            if (i && dit[i-1] >= 10) dit[i] += dit[i-1]/10, dit[i-1] %= 10;
        }
        while (dit[len-1] >= 10){
            dit[len] += dit[len-1] / 10;
            dit[len-1] %= 10;
            ++ len;
        }
    }
};
int main()
{
    big a; a.clear();
    a.len = 1; a.dit[0] = 1;
    for (int64 j = 0; j < 1000; ++ j) a * 2;
    int num = 0;
    for (int i = 0; i < a.len; ++ i) num += a.dit[i];
    out (num);
    return 0;
}

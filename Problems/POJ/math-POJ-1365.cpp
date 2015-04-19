/*
 * Author:  Plumrain
 * Created Time:  2013-10-18 15:41
 * File Name: math-POJ-1365.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 100000;
int n, prm[N+5], num[N+5];
int all, an[N+5], bn[N+5];

bool init()
{
    n = 0; CLR (prm); CLR (num);
    char c;
    scanf ("%c", &c);
    if (c == '0') return false;
    int tmp = 0;
    while (1){
        while (c >= '0' && c <= '9'){
            tmp = tmp * 10 + c - '0';
            scanf ("%c", &c);
        }
        prm[n] = tmp;
        scanf ("%c", &c);
        tmp = 0;
        while (c >= '0' && c <= '9'){
            tmp = tmp * 10 + c - '0';
            scanf ("%c", &c);
        }
        num[n++] = tmp;
        if (c == '\n') return true;
        tmp = 0; scanf ("%c", &c);
    }
}

int Mypow(int p, int n)
{
    int ret = 1;
    while (n > 0){
        if (n & 1) ret *= p;
        n >>= 1;
        p *= p;
    }
    return ret;
}

int cal()
{
    int ret = 1;
    for (int i = 0; i < n; ++ i)
        ret *= Mypow(prm[i], num[i]);
    return ret-1;
}

void inte_devide(int x)
{
    all = -1;
    for (int i = 2; i*i <= x;){
        if (!(x%i)){
            an[++all] = i;
            bn[all] = 0;
        }
        while (!(x%i)){
            ++ bn[all];
            x /= i;
        }
        if (i == 2) ++ i;
        else i += 2;
    }
    ++ all;
    if (x != 1){
        an[all] = x;
        bn[all++] = 1;
    }
}

int main()
{
    while (1){     
        bool ok = init();
        if (!ok) break;

        int x = cal(); 

        CLR (an); CLR (bn); 
        inte_devide(x);

        for (int i = all-1; i >= 0; -- i){
            if (i != all-1) printf (" ");
            printf ("%d %d", an[i], bn[i]);
        }
        printf ("\n");
    }
    return 0;
}



/*
 * Author:  Plumrain
 * Created Time:  2013-09-06 11:27
 * File Name: 
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

const int N = 100;

struct prob{
    int a, b;
    double p;
};

int n;
prob p;
double f[N+10][N+10];

double DP()
{
    double ret = 0;
    CLR (f);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++ i){
        int ma = p.a * i / p.b;
        f[i][0] = f[i-1][0] * (1 - p.p);
        for (int j = 1; j <= ma; ++ j){
            f[i][j] = f[i-1][j-1] * p.p + f[i-1][j] * (1-p.p);
        }
        ret += f[i-1][ma] * p.p; 
    }
    return ret;
}

int main()
{
    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        char xxx;
        scanf ("%d%c%d%d", &p.a, &xxx, &p.b, &n);
        p.p = (p.a+0.0) / p.b;
         
        //q为今天玩了，以后再也不玩纸牌的概率
        double q = 1 - DP();

        printf ("Case #%d: %d\n", ++test, (int)(1 / q));
    }
    return 0;
}

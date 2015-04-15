/*
 * Author:  Plumrain
 * Created Time:  2013-11-21 21:31
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
typedef long long int64;

int n, sum;
char s[5000], x;
int has[40000];
int d[4005][4005];

void init()
{
    x = '0';
    CLR (d); CLR (has);

    scanf ("%s", s);        
    n = strlen(s);
    for (int i = 0; i < n; ++ i){
        int tmp = 0;
        for (int j = i; j < n; ++ j){
            tmp += s[j] - x;
            ++ has[tmp];
        }
    }
}

int64 gao()
{
    int64 ret = 0;
    for (int i = 0; i < n; ++ i){
        int tmp = 0;
        for (int j = i; j < n; ++ j){
            tmp += s[j] - x;
            if (tmp && (sum%tmp == 0) && sum/tmp <= 9*n)
                ret += has[sum/tmp];
            else if (!tmp && !sum)
                ret += n*(n+1)/2;
        }
    }
    return ret;
}

int main()
{
    while (scanf ("%d", &sum) != EOF){
        init();
        cout << gao() << endl;
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 505;
int a[N][N];
int main(){
    int n;
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) 
                scanf ("%d", &a[i][j]);

        bool u = 1;
        for (int i = 0; i < n; ++ i) if (a[i][i]) u = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) 
                if (a[i][j] != a[j][i]) u = 0;

        for (int i = 0; i < n; ++ i) if (u){
            for (int j = (i&1 ? 0 : 1); j < n; j += 2) if (u)
                for (int k = j; k < n; k += 2) if (u){
                    int t = a[i][j] ^ a[i][k];
                    if (i & 1){
                        if (t & a[j][k]) u = 0;
                    } else if ((~a[j][k]) & t) u = 0;
                }
        }
        if (u) puts ("YES");
        else puts ("NO");
    }
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
int C[505][505], d[505][505];
const long long mod = 100003;
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
void init(){
    C[0][0] = 1;
    for (int i = 1; i < 505; ++ i){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j){
            C[i][j] = C[i-1][j]; add (C[i][j], C[i-1][j-1]);
        }
    }
    d[2][1] = 1;
    for (int i = 2; i < 501; d[++i][1] = 1){
        for (int j = 2; j < i; ++ j){
            for (int k = 1; k < j; ++ k){
                add (d[i][j], (long long)d[j][k] * C[i-j-1][j-k-1] % mod);
            }
        }
    }
}
int main(){
    init ();
    int _; scanf ("%d", &_);
    for (int __ = 0; __ < _; ++ __){
        int n; scanf ("%d", &n);
        int ans = 0;
        for (int i = 1; i < n; ++ i) add (ans, d[n][i]);
        printf ("Case #%d: %d\n", __+1, ans);
    }
    return 0;
}

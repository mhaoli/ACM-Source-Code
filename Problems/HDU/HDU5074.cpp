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
using namespace std;
int a[111][111], d[111][111], b[111];
const int inf = ~0u>>2;
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        int n, m; scanf ("%d%d", &n, &m);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < m; ++ j)
                scanf ("%d", &a[i][j]);

        for (int i = 0; i < n; ++ i){
            scanf ("%d", b + i); -- b[i];
        }
        memset (d, -1, sizeof d);
        if (b[0] < 0) for (int i = 0; i < m; ++ i) d[0][i] = 0;
        else d[0][b[0]] = 0;
        for (int i = 0; i < n-1; ++ i)
            for (int j = 0; j < m; ++ j) if (d[i][j] >= 0){
                if (b[i+1] < 0){
                    for (int k = 0; k < m; ++ k){
                        d[i+1][k] = max (d[i+1][k], d[i][j] + a[j][k]);
                    }
                } else{
                    d[i+1][b[i+1]] = max (d[i+1][b[i+1]], d[i][j] + a[j][b[i+1]]);
                }
            }
        int ans = 0;
        for (int i = 0; i < m; ++ i) if (d[n-1][i] > -1)
            ans = max (ans, d[n-1][i]);
        printf ("%d\n", ans);
    }
    return 0;
}

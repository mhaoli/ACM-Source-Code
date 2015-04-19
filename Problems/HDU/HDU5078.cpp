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
#define sqr(x) ((x)*(x))
using namespace std;
double dis (int x1, int y1, int x2, int y2){
    return sqrt (sqr (x1 - x2 + 0.0) + sqr (y1 - y2 + 0.0));
}
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        int n; scanf ("%d", &n);
        int t1, t2, t3, t, x, y;
        scanf ("%d%d%d", &t1, &t2, &t3);
        double ans = 0;
        for (int i = 1; i < n; ++ i){
            scanf ("%d%d%d", &t, &x, &y);
            double tmp = dis (x, y, t2, t3) / (t - t1);
            ans = ans < tmp ? tmp : ans;
            t1 = t; t2 = x; t3 = y;
        }
        printf ("%.10f\n", ans);
    }
    return 0;
}

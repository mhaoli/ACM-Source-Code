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
const int mod = 1000000007;
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        int n, ans = 0;;
        scanf ("%d", &n);
        for (int i = 0, t; i < n; ++ i){
            scanf ("%d", &t);
            t = (t * (i + 1ll) % mod) * (n - i) % mod;
            ans = (ans + t) % mod;
        }
        printf ("%d\n", ans);
    }
    return 0;
}

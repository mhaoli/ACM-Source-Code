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
long long a[1111];
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        int n; scanf ("%d", &n);
        for (int i = 0; i < n; ++ i){
            scanf ("%I64d", a + i);
        }
        std::sort (a, a + n, std::greater<long long>());
        for (int i = 40, j = 0; i >= 0 && j < n; -- i, ++ j){
            std::sort (a + j, a + n, std::greater<long long>());
            if (!a[n-1]) break;
            if (!(a[j] & (1ll<<i))){
                -- j; continue;
            }
            for (int k = j+1; k < n && (a[k] & (1ll<<i)); ++ k) a[k] ^= a[j];
        }
        std::sort (a, a + n, std::greater<long long>());
        if (!a[n-1]) puts ("Yes");
        else puts ("No");
    }
    return 0;
}

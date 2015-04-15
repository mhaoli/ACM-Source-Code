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
const int N = 1111;
int a[N], d[N], num[N];
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i) scanf ("%d", a + i);
        for (int i = 0; i < n; ++ i){
            d[i] = 1; num[i] = 1;
            for (int j = 0; j < i; ++ j) if (a[j] < a[i]){
                if (d[j] + 1 == d[i]) num[i] += num[j];
                else if (d[j] >= d[i]){
                    d[i] = d[j] + 1; num[i] = num[j];
                }
            }
        }
        int mx = -1, cnt = 0;
        for (int i = 0; i < n; ++ i) 
            if (d[i] > mx) mx = d[i], cnt = num[i];
            else if (d[i] == mx) cnt += num[i];
        int ans = cnt == 1 ? mx - 1 : mx;
        printf ("%d\n", ans);
    }
    return 0;
}

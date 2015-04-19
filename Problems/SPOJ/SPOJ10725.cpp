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
#define out(x) cout<<#x<<":"<<(x)<<endl
using namespace std;
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int N = 9 + (int)1e5;
int d[N][15], p[N][15];
char s[N], res[N];
vector<int> vec[111];
vector<int>::iterator it;
int main(){
    while (scanf ("%s", s) != EOF){
        int n = strlen (s);
        for (int i = 0; i < 10; ++ i) vec[i].clear ();
        for (int i = 0; i < n; ++ i)
            vec[s[i]-'0'].push_back (i);
        for (int i = 0, sz; i < 10; ++ i){
            sz = vec[i].size (); 
            d[1][i] = sz ? vec[i][sz-1] : -1;
            p[1][i] = i;
        }
        
        int i, j, ans = -1, k;
        for (i = 2; i <= n + 2; ++ i){
            for (j = i>2 ? 1 : 0; j < 10; ++ j) if (d[i-1][j] < 0){
                ans = j; break;
            }
            if (ans != -1) break;

            for (j = 0; j < 10; ++ j) {
                d[i][j] = n;
                for (k = 0; k < 10; ++ k){
                    it = lower_bound (vec[j].begin(), vec[j].end(), d[i-1][k]);
                    if (chmin (d[i][j], it == vec[j].begin() ? -1 : *(it-1)))
                        p[i][j] = k;
                }
            }
        }
        --i;
        int cnt = 0;
        while (i){
            res[cnt++] = ans + '0';
            ans = p[i--][ans];
        }
        res[cnt] = 0;
        puts (res);
    }
    return 0;
}

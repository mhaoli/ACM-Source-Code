#include<cstdio>
#include<algorithm>
#include<cmath>
#include<functional>
using namespace std;
int a[111], b[111], ans[111];
bool cmp (int a, int b){
        int t1 = a % 10, t2 = b % 10;
        return t1 == t2 ? a < b : t1 < t2;
}
int main(){
        int _; scanf ("%d", &_);
        for (int n, m; _--;){
                scanf ("%d%d", &n, &m);
                for (int i = 0; i < n; ++i) scanf ("%d", a + i);
                for (int j = 0; j < m; ++j) scanf ("%d", b + j);
                sort (a, a + n);
                n = unique (a, a + n) - a;
                sort (b, b + m);
                m = unique (b, b + m) - b;

                sort (a, a + n, greater<int>());
                sort (b, b + m, greater<int>());

                int ans_len = 0;
                for (int i = 0, j, l, k; i < n; ++i){
                        for (j = 0; j < m; ++j){
                                for (l = 1; i+l <= n && j+l <= m && a[i+l-1] == b[j+l-1]; ++ l);
                                if (--l > ans_len){
                                        ans_len = l;
                                        for (k = 0; k < l; ++ k) ans[k] = a[i+k];
                                }
                        }
                }
                if (ans_len == 0) puts ("NONE");
                else{
                        for (int i = 0; i < ans_len; ++i) printf ("%d%c", ans[i], " \n"[i==ans_len-1]);
                        sort (ans, ans + ans_len, cmp);
                        for (int i = 0; i < ans_len; ++i) printf ("%d%c", ans[i], " \n"[i==ans_len-1]);
                }
        }
        return 0;
}

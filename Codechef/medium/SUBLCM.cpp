#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++ it)
const int N = 9 + (int)1e6;
std::vector<int> vec[N];
int a[N>>3], idx[N], f[N];
void init (int n){
    for (int i = 2; i <= n; ++ i) if (!idx[i]){
        for (int j = i; j <= n; j += i)
            if (!idx[j]) idx[j] = i;
    }
}
int main(){
    init (N - 5);
    int T; scanf ("%d", &T);
    while (T--){
        int n, mx = 0;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i){
            scanf ("%d", a + i);
            mx = std::max (mx, a[i]);
            if (a[i] == 1) continue;
            vec[idx[a[i]]].push_back (i);
        }
        memset (f, -1, sizeof f);
        for (int i = 2; i <= mx; ++ i){
            sort (vec[i].begin(), vec[i].end());
            foreach (it, vec[i]){
                if (it != vec[i].begin ()){
                    f[*it] = std::max (f[*it], *(it-1));
                }
                while (a[*it] % i == 0) a[*it] /= i;
                vec[idx[a[*it]]].push_back (*it);
            }
            vec[i].clear ();
        }
        int p = -1, ans = -1;
        for (int i = 0; i < n; ++ i){
            p = std::max (p, f[i]);
            if (p < i-1) ans = std::max (ans, i - p);
        }
        printf ("%d\n", ans);
    }
    return 0;
}

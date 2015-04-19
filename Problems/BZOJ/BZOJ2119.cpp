#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++ it)
const int N = 9 + (int)5e4;
int s[N], n, m, cnt, ans;
std::set<int> st;
std::map<int, int> has;
struct RMQ{
    int mi[N][25], lg2[N];
    void init (int *a, int n){
        lg2[0] = -1;
        for (int i = 1; i <= n; ++ i){
            mi[i][0] = a[i];
            lg2[i] = lg2[i>>1] + 1;
        }
        for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
            for (int i = 1; i + l - 1 <= n; ++ i)
                mi[i][j] = std::min (mi[i][j-1], mi[i+(l>>1)][j-1]);
        }
    }
    int query (int a, int b){
        int k = lg2[b - a + 1];
        return std::min (mi[a][k], mi[b-(1<<k)+1][k]);
    }
};
struct SA{
    RMQ rmq;
    int n, sa[N], rank[N], h[N], wa[N], wb[N], wt[N], wv[N];
    int cmp (int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }
    void build (int *r, int n, int m){
        r[n] = 0; this->n = n++;
        int i, j, p, *x=wa, *y=wb, *t;
        for (i = 0; i < m; ++ i) wt[i] = 0;
        for (i = 0; i < n; ++ i) wt[x[i]=r[i]]++;
        for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
        for (i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
        for (j = 1, p = 1; p < n; j <<= 1, m = p){
            for (p = 0, i = n-j; i < n; ++ i) y[p++] = i;
            for (i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (i = 0; i < n; ++ i) wv[i] = x[y[i]];
            for (i = 0; i < m; ++ i) wt[i] = 0;
            for (i = 0; i < n; ++ i) wt[wv[i]]++;
            for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
            for (i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
            for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i = 1; i < n; ++ i)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
    }
    void calh (int *r){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for (i = 0; i < n; h[rank[i++]] = k)
            for (k?k--:0, j = sa[rank[i]-1]; r[i+k]==r[j+k]; ++ k);
    }
    void rmq_init (int n){
        rmq.init (h, n);
    }
    int lcp (int a, int b){
        if (a == b) return n - a;
        a = rank[a]; b = rank[b];
        if (a > b) std::swap (a, b);
        return rmq.query (a + 1, b);
    }
}sa1, sa2;
void calc2 (int l){
    for (int i = 0; i+l+m < n; i += l){
        int l2 = std::min (l, sa1.lcp (i, i+l+m)), l1 = std::min (sa2.lcp (n-i-1, n-i-l-m-1), l);
        if (l1 + l2 - 1 >= l) ans += std::min (l1 + l2 - l, l1);
    }
}
void calc1 (int l){
    for (int i = 0, j = l+m; j + l <= n; ++ i, ++ j){
        ++ ans;
        for (int t = 0; t < l; ++ t){
            if (s[i+t] != s[j+t]){
                -- ans; break;
            }
        }
    }
}
int main(){
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf ("%d", s + i);
        if (i) st.insert (s[i-1]-=s[i]);
    }
    -- n;
    cnt = 1;
    foreach (it, st) has[*it] = cnt++;
    for (int i = 0; i < n; ++ i) s[i] = has[s[i]];

    sa1.build (s, n, cnt);
    sa1.calh (s);
    sa1.rmq_init (n);
    std::reverse (s, s + n);
    sa2.build (s, n, cnt);
    sa2.calh (s);
    sa2.rmq_init (n);

    for (int i = 1; i <= (n>>1); ++ i){
        if (i < m) calc1 (i);
        else calc2 (i);
    }
    printf ("%d\n", ans);
    return 0;
}

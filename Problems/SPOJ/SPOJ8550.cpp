#include<bits/stdc++.h>
typedef unsigned long long ULL;
const int N = 9 + (int)1e5;
struct RMQ{
    int mi[N][30], lg2[N];
    void init (int n, int *a){ //a: 0...n-1
        for (int i = 0; i < n; ++ i){
            mi[i][0] = i;
            lg2[i] = (!i ? -1 : lg2[i>>1] + 1);
        }
        for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
            for (int i = 0; i + l - 1 < n; ++ i)
                mi[i][j] = a[mi[i][j-1]] <= a[mi[i+(l>>1)][j-1]] ? mi[i][j-1] : mi[i+(l>>1)][j-1];
        }
    }
    int query (int *r, int a, int b){ //[a, b]
        int k = lg2[b - a + 1];
        return r[mi[a][k]] <= r[mi[b-(1<<k)+1][k]] ? mi[a][k] : mi[b-(1<<k)+1][k];
    }
};
struct SA{
    RMQ rmq;
    int n;
    int sa[N], rank[N], h[N];
    int wa[N], wb[N], wv[N], wt[N];
    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }
    void build(int *r, int n, int m)
    {
        r[n] = 0; this -> n = n ++;
        
        int i, j, p, *x=wa, *y=wb, *t;
        for (i = 0; i < m; ++ i) wt[i] = 0;
        for (i = 0; i < n; ++ i) wt[x[i]=r[i]] ++;
        for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
        for (i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for (p = 0, i = n-j; i < n; i++) y[p++] = i;
            for (i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (i = 0; i < n; ++ i) wv[i] = x[y[i]];
            for (i = 0; i < m; ++ i) wt[i] = 0;
            for (i = 0; i < n; ++ i) wt[wv[i]] ++;
            for (i = 1; i < m; ++ i) wt[i] += wt[i-1];
            for (i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
            for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        return;
    }
    void calh(int *r){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for (i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
    void init_min (){
        rmq.init (n, rank);
    }
    void take_min (int &p, int t1, int t2){
        int t = rmq.query (rank, t1, t2);
        if (rank[p] > rank[t]) p = t;
    }
}sa;

const ULL seed = 30007;
int n;
char s[N], ans[N];
ULL has[N], pp[N];
int Hash (int t1, int t2){
    return t1 ? has[t2]-has[t1-1]*pp[t2-t1+1] : has[t2];
}
int prefix (int t1, int t2){
    int ans = 0;
    for (int m, l = 0, r = t1 + 1; l <= r; ){
        m = l + r >> 1;
        if (Hash (t1-m+1, t1) == Hash (t2-m+1, t2)) l = (ans = m) + 1;
        else r = m - 1;
    }
    return ans;
}
int suffix (int t1, int t2){
    int ans = 0;
    for (int m, l = 0, r = n-t2; l <= r; ){
        m = l + r >> 1;
        if (Hash (t1, t1+m-1) == Hash (t2, t2+m-1)) l = (ans = m) + 1;
        else r = m - 1;
    }
    return ans;
}
void solve (int &ans, int &p, int l){
    for (int i = 0, t1, t2, t; i+l <= n; i += l){
        t1 = std::min (prefix (i, i + l), l); 
        t2 = std::min (suffix (i, i+l), l);
        t = t1 + t2 - 1 - l;
        if (t >= 0){
            if (ans < l) p = i - t1 + 1;
            sa.take_min (p, i-t1+1, std::min (i-t1+1+t, i));
            ans = l;
        }
    }
}
int ss[N];
int main(){
    scanf ("%s", s);
    n = strlen (s);
    for (int i = 0; i < n; ++ i) ss[i] = s[i] - 'a' + 1;
    sa.build (ss, n, 30);
    sa.calh (ss);
    sa.init_min ();

    pp[0] = 1;
    for (int i = 1; i <= n; ++ i) pp[i] = pp[i-1]*seed;
    for (int i = 0; i < n; ++ i) has[i] = i ? has[i-1]*seed + s[i]-'a'+1 : s[i]-'a'+1;

    int len = 0, p = 0;
    for (int i = 1; (i<<1) <= n; ++ i){
        solve (len, p, i);
    }
    printf ("%d\n", len);
    int tot = 0;
    for (int i = 0; i < len; ++ i) ans[tot++] = s[p+i];
    ans[tot] = 0;
    puts (ans);
    return 0;
}

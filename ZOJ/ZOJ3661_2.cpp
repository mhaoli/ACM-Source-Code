#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 9 + (int)1e5;
const int mod = 777777777;
const ULL seed = 30007;
ULL pp[N], a[N];
pair<int,int> pld[N], sot[N];
int len[N<<1], ss[N], cnt[N], val[30], b[N];
long long tp[N];
char s[N];
set<ULL> st;
ULL ask_hash (int l, int r){
    return l ? a[r] - a[l-1]*pp[r-l+1] : a[r];
}
int ask_hash2 (int l, int r){
    return l ? ((b[r] - b[l-1]*tp[r-l+1]%mod) + mod)%mod : b[r];
}
void Manacher (char *s, int *len, int n){
    for (int i = 0; i < (n<<1); ++ i) len[i] = 0;
    for (int i = 0, j = 0, k; i < (n<<1); i += k, j = max (j-k,0)){
        while (i - j >= 0 && i + j + 1 < (n<<1) && s[(i-j)>>1] == s[(i+j+1)>>1]) ++ j;
        len[i] = j;
        for (k = 1; i-k >= 0 && j-k >= 0 && len[i-k] != j-k; ++ k){
            len[i+k] = min (len[i-k], j-k);
        }
    }
}
int mi[N][30], lg2[N];
void rmq_init (int n, int *a){
    lg2[0] = -1;
    for (int i = 1; i <= n; ++ i){
        mi[i][0] = a[i];
        lg2[i] = lg2[i>>1] + 1;
    }
    for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
        for (int i = 1; i+l-1 <= n; ++ i)
            mi[i][j] = min (mi[i][j-1], mi[i+(l>>1)][j-1]);
    }
}
int rmq_query (int a, int b){
    int k = lg2[b - a + 1];
    return min (mi[a][k], mi[b-(1<<k)+1][k]);
}
struct SA{
    int n, sa[N], rank[N], h[N], wa[N], wb[N], wv[N], wt[N];
    int cmp (int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }
    void build (int *r, int n, int m){
        r[n] = 0; this->n = n++;
        int i, j, p, *x = wa, *y = wb, *t;
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
            for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; ++ i)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
    }
    void calh (int *r){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for (i = 0; i < n; h[rank[i++]] = k)
            for (k?k--:0, j=sa[rank[i]-1]; r[i+k]==r[j+k]; k ++);
        return;
    }
    int cal_cnt (int sta, int key){
        sta = rank[sta];
        int res1, res2;
        for (int l = 1, r = sta, m = (l+r)>>1; m = (l+r)>>1, l <= r; ){
            if (m == sta || rmq_query (m+1, sta) >= key) res1 = m, r = m - 1;
            else l = m + 1;
        }
        for (int l = sta, r = n, m; m = (l+r)>>1, l <= r; ){
            if (m == sta || rmq_query (sta+1, m) >= key) res2 = m, l = m + 1;
            else r = m - 1;
        }
        return res2 - res1 + 1;
    }
}sa;
int main(){
    for (int i = 0; i < N; ++ i){
        pp[i] = i ? pp[i-1]*seed : 1;
        tp[i] = i ? tp[i-1]*26%mod : 1;
    }
    int T; scanf ("%d", &T);
    while (T--){
        int n, q;
        scanf ("%d%d%s", &n, &q, s);
        Manacher (s, len, n);
        int tot = 0;
        for (int i = 0; i < n; ++ i) a[i] = i ? s[i]+a[i-1]*seed : s[i];
        st.clear ();
        for (int i = 0; i < (n<<1); ++ i){
            for (int j = (i>>1) + (len[i]>>1), k = len[i]; k > 0; -- j, k -= 2){
                ULL t = ask_hash (j - k + 1, j);
                set<ULL>::iterator it = st.find (t);
                if (it == st.end ()){
                    st.insert (t); 
                    pld[tot].first = j - k + 1;
                    pld[tot++].second = j;
                } else break;
            }
        }

        for (int i = 0; i < n; ++ i) ss[i] = s[i] - 'a' + 1;
        sa.build (ss, n, 30);
        sa.calh (ss);
        rmq_init (n, sa.h);
        for (int i = 0; i < tot; ++ i){
            cnt[i] = sa.cal_cnt (pld[i].first, pld[i].second - pld[i].first + 1);
        }

        while (q--){
            long long K;
            scanf ("%lld", &K);
            for (int i = 0; i < 26; ++ i) scanf ("%d", val + i);
            for (int i = 0; i < n; ++ i) b[i] = i ? (val[s[i]-'a'] + b[i-1]*26ll)%mod : val[s[i]-'a'];
            for (int i = 0; i < tot; ++ i){
                sot[i].first = ask_hash2 (pld[i].first, (pld[i].first + pld[i].second) >> 1);
                sot[i].second = cnt[i];
            }
            sort (sot, sot + tot);
            int i;
            for (i = 0; i < tot; ++ i){
                if (K <= sot[i].second) break;
                else K -= sot[i].second;
            }
            printf ("%d\n", sot[i].first);
        }
        puts ("");
    }
}

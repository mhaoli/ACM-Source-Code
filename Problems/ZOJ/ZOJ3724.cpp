#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = (T).begin(); it != (T).end(); ++ it)
using namespace std;
typedef long long ll;
template<class T> bool chmax (T &a, const T &b){ return a < b ? a = b, 1 : 0;}
const int N = 9 + (int)1e5;
const int inf = ~0u>>1;
ll sum[N], ans[N<<1];
vector<pair<int, int> > p1[N], p2[N], q1[N], q2[N];
pair<int, int> tmp;
pair<int, ll> tmp2;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
ll add[N<<2], mx[N<<2];
void Down (int rt){
    if (add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        mx[rt<<1] += add[rt];
        mx[rt<<1|1] += add[rt];
        add[rt] = 0;
    }
}
void Up (int rt){
    mx[rt] = mx[rt<<1];
    chmax (mx[rt], mx[rt<<1|1]);
}
void init (){
    memset (add, 0, sizeof add);
    memset (mx, 0, sizeof mx);
}
void addIt (ll q){
    add[1] += q; mx[1] += q;
}
void insert (int q, ll v, int l, int r, int rt){
    if (l != r){
        int m = (l + r) >> 1;
        Down (rt);
        if (q <= m) insert (q, v, lson);
        else insert (q, v, rson);
        Up (rt);
    } else chmax (mx[rt], v);
}
ll query (int ql, int qr, int l, int r, int rt){
    if (ql <= l && r <= qr){
        return mx[rt];
    }

    int m = (l + r) >> 1;
    ll ret = 0;
    Down (rt);
    if (ql <= m) ret = query (ql, qr, lson);
    if (qr > m) chmax (ret, query (ql, qr, rson));
    Up (rt);
    return ret;
}

const int UP = 100000;
int main(){
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        for (int i = 1, t; i < n; ++ i){
            scanf ("%d", &t);
            sum[i] = sum[i-1] + t;
        }
        for (int i = 0; i < n; ++ i){
            p1[i].clear (), p2[i].clear ();
            q1[i].clear (), q2[i].clear ();
        }
        for (int i = 0, u, v, l; i < m; ++ i){
            scanf ("%d%d%d", &u, &v, &l);
            if ((--u) < (--v)){
                tmp2.first = u;
                tmp2.second = sum[v] - sum[u] - l;
                if (tmp2.second > 0) p1[v].push_back (tmp2);
            } else{
                tmp2.first = v;
                tmp2.second = UP - l + sum[v];
                p2[u].push_back (tmp2);
            }
        }

        int qn; scanf ("%d", &qn);
        for (int i = 0, t1, t2; i < qn; ++ i){
            scanf ("%d%d", &t1, &t2);
            tmp.second = i;
            if ((--t1) < (--t2)){
                tmp.first = t1;
                q1[t2].push_back (tmp);
                ans[i] = sum[t2] - sum[t1];
            } else if (t1 == t2){
                ans[i] = 0;
            } else{
                tmp.first = t2;
                q2[t1].push_back (tmp);
                ans[i] = sum[t2] + UP;
            }
        }

        init ();
        for (int i = 0; i < n; ++ i){
            foreach (it, p1[i]) insert ((*it).first, (*it).second, 0, n-1, 1);
            foreach (it, q1[i]) ans[(*it).second] -= query ((*it).first, n-1, 0, n-1, 1);
        }
        init ();
        for (int i = n-1; i >= 0; -- i){
            if (i != n-1) addIt (sum[i]-sum[i+1]);
            foreach (it, p2[i]) insert ((*it).first, (*it).second, 0, n-1, 1);
            foreach (it, q2[i]) ans[(*it).second] -= query (0, (*it).first, 0, n-1, 1);
        }
        for (int i = 0; i < qn; ++ i)
            printf ("%lld\n", ans[i]);
    }
    return 0;
}

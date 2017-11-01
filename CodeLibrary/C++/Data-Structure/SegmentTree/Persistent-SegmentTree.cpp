// problem: BZOJ2120
const int N = 9 + (int)1e4;
const int M = 9 + (int)1e4;
struct DS{
#define lowbit(x) ((x)&(-x))
    struct nod{
        nod *ls, *rs;
        int v;
    }memo[N*30 + M*200], *bat, *rt0[N], *rt[N], Tnull, *null;
    bool FG;
    int n, up, last[N+M];
    void init (){
        bat = memo;
        null = &Tnull;
        null->ls = null->rs = null;
        null->v = 0;
        for (int i = 0; i <= n; ++ i) rt[i] = null;
        rt0[0] = null;
    }
    void build (int _n, int _up, int *a){
        n = _n; up = _up;
        init ();
        FG = 1;
        nod *x;
        //memset (last, 0, sizeof last);
        for (int i = 1; i <= n; ++ i){
            if (last[a[i]]){
                insert (last[a[i]], -1, 0, up, x = rt0[i-1]);
                insert (i, 1, 0, up, rt0[i] = x);
            } else{
                //puts ("b");
                insert (i, 1, 0, up, rt0[i] = rt0[i-1]);
            }
            last[a[i]] = i;
        }
        FG = 0;
    }
    void insert (int v, int t, int l, int r, nod *&x){
        if (FG || x == null){
            *bat = *x; x = bat++;
        }
        x->v += t;
        if (l == r) return;
        int m = l + r >> 1;
        if (v <= m) insert (v, t, l, m, x->ls);
        else insert (v, t, m+1, r, x->rs);
    }
    int query (int ql, int qr, int l, int r, nod *x){
        if ((ql <= l && r <= qr) || x == null) return x->v;
        int m = l + r >> 1, ret = 0;
        if (ql <= m) ret = query (ql, qr, l, m, x->ls);
        if (qr > m) ret += query (ql, qr, m+1, r, x->rs);
        return ret;
    }
    int solve (int l, int r){
        int ret = query (l, r, 0, up, rt0[r]);
        for (int i = r; i <= n; i += lowbit(i)){
            ret += query (l, r, 0, up, rt[i]);
        }
        return ret;
    }
    void modify (int p, int v, int l, int r){
        //printf ("l:%d r:%d p:%d v:%d\n", l, r, p, v);
        for (; r; r -= lowbit(r)) insert (p, v, 0, up, rt[r]);
        for (-- l; l; l -= lowbit(l)) insert (p, -v, 0, up, rt[l]);
    }
}T;
int main(){
    T.build (n, tot, a);        //tot is the max value in Segment Tree
    T.modify (p, v, l, r);
    T.solve (l, r);
    return 0;
}

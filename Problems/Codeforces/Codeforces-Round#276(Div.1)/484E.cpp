#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
int n;
struct Info{
    int l, r, mx, sz;
    Info (){ l = r = mx = sz = 0; }
    friend Info operator + (const Info &a, const Info &b){
        Info ret;
        ret.mx = std::max (a.mx, b.mx);
        ret.mx = std::max (ret.mx, a.r + b.l);
        ret.l = (a.l == a.sz && a.sz) ? a.l + b.l : a.l;
        ret.r = (b.r == b.sz && b.sz) ? b.r + a.r : b.r;
        ret.sz = a.sz + b.sz;
        return ret;
    }
}Temp;
struct Node{
    Node *ch[2];
    int l, r;
    Info info;
    void insert (int p, int v);
    Info query (int l, int r);
    void upd (){
        info = ch[0]->info + ch[1]->info;
    }
}mem[N*20], *bat=mem, Tnull, *null=&Tnull, *rt[N];
Node* New_Node (Node *x, int l = 1, int r = n){
    *bat = *x;
    bat->l = l; bat->r = r;
    return bat++;
}
void Node::insert (int p, int v){
    if (l == r){
        info.l = info.r = info.mx = info.sz = 1;
        return;
    }
    int m = l + r >> 1;
    if (p <= m) (ch[0] = New_Node (ch[0], l, m)) -> insert (p, v);
    else (ch[1] = New_Node (ch[1], m+1, r)) -> insert (p, v);
    upd ();
    info.sz = r - l + 1;
}
Info Node::query (int ql, int qr){
    if (this == null) return Temp;
    if (ql <= l && r <= qr) return info;
    int m = l + r >> 1;
    Info ret = Temp;
    if (ql <= m) ret = ch[0]->query (ql, qr);
    if (qr > m) ret = ret + ch[1]->query (ql, qr);
    return ret;
}

void init (){
    null->ch[0] = null->ch[1] = null;
    rt[0] = null;
}
std::pair<int, int> a[N];
int ql, qr, w;
bool check (int ans){
    int p = 0;
    for (int l = 1, r = n, m; l <= r; ){
        m = l + r >> 1;
        if (a[m].first >= ans) l = (p = m) + 1;
        else r = m - 1;
    }
    return (rt[p]->query (ql, qr)).mx >= w;
}
int main(){
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf ("%d", &a[i].first);
        a[i].second = i;
    }
    init ();
    sort (a + 1, a + n + 1, std::greater<std::pair<int, int> >());
    for (int i = 1; i <= n; ++i){
        (rt[i] = New_Node (rt[i-1])) -> insert (a[i].second, 1);
    }
    int q; scanf ("%d", &q);
    for (int l, r, m, res; q--;){
        scanf ("%d%d%d", &ql, &qr, &w);
        l = 1; r = a[1].first; res = 0;
        while (l <= r){
            m = l + r >> 1;
            if (check (m)) l = (res = m) + 1;
            else r = m - 1;
        }
        printf ("%d\n", res);
    }
    return 0;
}

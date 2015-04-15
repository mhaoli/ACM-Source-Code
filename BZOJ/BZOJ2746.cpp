#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = (T).begin(); it != (T).end(); ++ it)
using namespace std;
const int mod = 1000000007;
const int N = 9 + (int)1e6;
const int S = 30;
struct nod;
struct edge{
    nod *v; edge *nxt;
    void add (nod *t, edge *n){ v = t; nxt = n;}
}memo2[N], *stp=memo2;
void adde (nod *v, edge *&hd){
    stp->add (v, hd); hd = stp++;
}

struct nod{
    nod *ch[S], *f, *fa, *belong;
    int dep, sz, key;
    edge *head;
    nod* go (int c);
}memo[N], *bat=memo, *rt=bat++, *q[N], *pos[N];
nod *nod::go (int c){
    if (!ch[c]){
        bat->fa = this;
        ch[c] = bat++;
        ch[c]->key = (this->key * 26ll + c) % mod;
    }
    return ch[c];
}

int len[N];
void insert (char *s, int fg){
    nod *x = rt;
    for (len[fg] = 0; s[0]; ++ s, ++ len[fg]){
        x = x->go (s[0]-'a');
    }
    pos[fg] = x; 
}
void build_AC (){
    int ql = 0, qr = 0;
    q[qr++] = rt;
    for (nod *x, *v, *last; ql != qr; ++ ql){
        x = q[ql];
        for (int c = 0; c < 26; ++ c) if (x->ch[c]){
            v = x->ch[c];
            last = x->f;
            while (last && last->ch[c] == 0) last = last->f;
            if (last) v->f = last->ch[c];
            else v->f = rt;
            adde (v, v->f->head);
            q[qr++] = v;
        }
    }
}
nod *Q[N];
void fail_tree (){
    int ql = 0, qr = 0;
    Q[qr++] = rt; rt->dep = 0;
    for (nod *x; ql != qr; ++ ql){
        x = Q[ql];
        for (edge *p = x->head; p; p = p->nxt){
            p->v->dep = x->dep + 1;
            Q[qr++] = p->v;
        }
    }
    for (ql = qr-1; ql; -- ql) Q[ql]->f->sz += ++(Q[ql]->sz);
    for (nod *x, *id; ql != qr; ++ ql){
        x = Q[ql];
        if (!x->belong) x->belong = x;
        int mx = -1;
        for (edge *p = x->head; p; p = p->nxt){
            if (p->v->sz > mx) mx = p->v->sz, id = p->v;
        }
        if (~mx) id->belong = x->belong;
    }
}

nod *LCA (nod *t1, nod *t2){
    while (true){
        if (t1->dep > t2->dep) swap (t1, t2);
        if (t1->belong == t2->belong) return t1;
        if (t1->belong->dep < t2->belong->dep) swap (t1, t2);
        t1 = t1->belong->f;
    }
    return t2;
}

vector<pair<int, int> > an[N];
nod *query[N<<1];

void calc (nod *x, vector<pair<int, int> > &a){
    for (int sz=a.size(), len=0, tpos=0; x != rt && tpos < sz; ++ len, x = x->fa){
        while (tpos < sz && a[tpos].first == len){ 
            query[a[tpos].second] = x;
            ++ tpos;
        }
    }
}

char s[N];
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf ("%s", s);
        insert (s, i);
    }
    build_AC ();
    fail_tree ();

    int m; scanf ("%d", &m);
    for (int i = 0, t1, t2, t3, t4; i < m; ++ i){
        scanf ("%d%d%d%d", &t1, &t2, &t3, &t4); -- t1; -- t3;
        an[t1].push_back (pair<int,int> (len[t1]-t2, i<<1));
        an[t3].push_back (pair<int,int> (len[t3]-t4, i<<1|1));
    }
    memset (query, 0, sizeof query);
    for (int i = 0; i < n; ++ i){
        sort (an[i].begin (), an[i].end ());
        calc (pos[i], an[i]);
    }
    for (int i = 0; i < m; ++ i) 
        printf ("%d\n", LCA(query[i<<1], query[i<<1|1])->key);
    return 0;
}

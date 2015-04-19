#include<bits/stdc++.h>
const int N = 9 + (6e5);
const int S = 30;
struct SAM{
    struct State{
        State *suf, *ch[S], *nxt;
        int mx, mi;
        bool vis;
        long long v;
        void clear(){
            suf = 0; vis = v = mx = 0;
            memset (ch, 0, sizeof ch);
        }
    }*rt, *last;

    int L;
    State memo[N<<1], *bat;
    State *head[N];

    void init (){
        L = 0;
        bat = memo;
        rt = last = bat ++; 
        rt->clear();
    }
    void extend (int w){
        ++ L;
        State *p = last, *np = bat++; 
        np->clear();
        np->mx = p->mx + 1;
        while (p && !p->ch[w])
            p->ch[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->ch[w];
            if (p->mx + 1 == q->mx) np->suf = q;
            else{
                State *nq = bat++; 
                nq->clear();
                memcpy (nq->ch, q->ch, sizeof q->ch);
                nq->mx = p->mx + 1;
                nq->suf = q->suf;
                q->suf = nq;
                np->suf = nq;
                while (p && p->ch[w] == q)
                    p->ch[w] = nq, p = p->suf;
            }
        }
        last = np;
    }

    void topo (){
        memset (head, 0, sizeof head);
        for (State *p = memo; p != bat; ++ p){
            p->nxt = head[p->mx], head[p->mx] = p;
        }
    }

    /*********************/
    std::set<long long> res;
    void solve (){
        res.clear ();
        for (int i = L; i; -- i)
            for (State *p = head[i]; p; p = p->nxt) if (!p->vis){
                p->vis = 1;
                if (p->suf) p->suf->v |= p->v;
            }
        rt->vis = 0;
        for (int t = 0; t <= L; ++ t)
            for (State*p = head[t]; p; p = p->nxt) if (!p->vis){
                if (t) res.insert (p->v);
                for (int i = 0; i < 26; ++ i)
                    if (p->ch[i]) p->ch[i]->vis = 0;
            }
        printf ("%lld\n", (long long)res.size ());
    }
}sam;
char s[N>>3];
int main(){
    int n;
    while (scanf ("%d", &n) != EOF && n){
        sam.init ();
        for (int i = 0; i < n; ++ i){
            scanf ("%s", s);
            for (int j = 0; s[j]; ++ j){
                sam.extend (s[j] - 'a');
                sam.last->v |= 1ll << i;
            }
            sam.extend (28);
            sam.last->vis = 1;
        }
        sam.topo ();
        sam.solve ();
    }
    return 0;
}

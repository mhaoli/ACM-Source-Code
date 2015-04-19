/*
 * Author:  Plumrain
 * from WJMZBMR's code
 * Created Time:  2014/8/15 0:43:10
 * File Name: Ahd-Corasick.cpp
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)

const int maxn = ;
const int maxs = ;
struct nod{
    nod *ch[maxs+5], *f;
    nod *jump[maxs+5];
    int v;
    nod *go (int c);
}*bat;

nod *nod::go (int c){
    if (ch[c] == 0) ch[c]=bat++, clr (ch[c]->ch, 0), ch[c]->v = 0;
    return ch[c];
}

struct AC{
    nod memo[maxn], *rt, *q[maxn];
    void newnod (nod *&o){
        o = bat++; clr (o->ch, 0); o->v = 0;
    }
    void init (){
        bat = memo; newnod (rt);
    }
    int idx (nod *x){
        return x - memo;
    }
    void insert (int *s, int n, int v){
        nod *x = rt;
        repf (i, 0, n-1) x = x->go (s[i]);
        x->v += v;
    }
    void build(){
        int ql = 0, qr = 0;
        q[qr++] = rt;
        while (ql != qr){
            nod *x = q[ql++];
            repf (c, 0, maxs-1){
                nod *v = x->ch[c];
                if (!v) continue;

                nod *last = x->f;
                while (last && last->ch[c] == 0) last = last->f;
                if (last) v->f = last->ch[c];
                else v->f = rt;
                q[qr++] = v;
            }
        }

        repf (i, 0, maxs-1) rt->jump[i] = rt->ch[i] ? rt->ch[i] : rt;
        repf (i, 1, qr-1){
            nod *x = q[i];
            repf (j, 0, maxs-1)
                if (x->ch[j]) x->jump[j] = x->ch[j];
                else x->jump[j] = x->f->jump[j];
        }

        repf (i, 1, qr-1){
            nod *x = q[i];
            if (x->f) x->v += x->f->v;
        }
    }
};

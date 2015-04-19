#include<cstdio>
#include<algorithm>
#include<cmath>
#include<functional>
#include<cstring>
using namespace std;
const int M = 1111, N = 5100005;
void transform (char *s, char *t){
        char tmp;
        int cnt = 0;
        while (s[0]){
                if (s[0] == '['){
                        ++s;
                        for (cnt = 0; s[0] >= '0' && s[0] <= '9'; ++s){
                                cnt = cnt * 10 + s[0] - '0';
                        }
                        tmp = s[0]; ++s; ++s;
                        while (cnt){
                                t[0] = tmp; ++t; --cnt;
                        }
                } else{
                        t[0] = s[0]; ++s; ++t;
                }
        }
        t[0] = 0;
}

int top;
char s[M], s2[M], str[N], str2[N];
struct Node;
struct Edge{
        Node *v; Edge *nxt;
        void add (Node *t, Edge*n){ v = t; nxt = n;}
}mem2[2800000], *stp;
void adde (Node *v, Edge *&hd){
        stp->add (v, hd); hd = stp++;
}
struct Node{
        Node *ch[26], *jump[26], *f, *belong, *chf;
        int v, dep, sz, vis, l, r;
        Edge *head;
        void clear (){
                vis = sz = v = 0;
                head = 0;
                belong = 0;
                memset (ch, 0, sizeof ch);
        }
        Node *go (int c);
}mem[2800000], *bat, *rt, *q[2800000], *Q[2800000];
void New_Node (Node *&o){
        o = bat++; o->clear (); 
}
Node* Node::go (int c){
        if (!ch[c]) New_Node (ch[c]), ch[c]->chf = this;
        return ch[c];
}
void insert (char *s, int v){
        Node *x = rt;
        for (; s[0]; ++s) x = x->go (s[0] - 'A');
        x->v = v;
}
void build (){
        int ql = 0, qr = 0, c;
        q[qr++] = rt;
        for (Node *x, *v, *last; ql != qr; ++ql){
                x = q[ql];
                if (ql) adde (x, x->f->head);
                for (c = 0; c < 26; ++c){
                        v = x->ch[c];
                        if (!v) continue;
                        last = x->f;
                        while (last && !last->ch[c]) last = last->f;
                        if (last) v->f = last->ch[c];
                        else v->f = rt;
                        q[qr++] = v;
                }
        }
        for (c = 0; c < 26; ++c) rt->jump[c] = rt->ch[c] ? rt->ch[c] : rt;
        Node *x;
        for (ql = 1; ql < qr; ++ ql){
                x = q[ql];
                for (c = 0; c < 26; ++c){
                        if (x->ch[c]) x->jump[c] = x->ch[c];
                        else x->jump[c] = x->f->jump[c];
                }
        }
}
void find (char *s){
        Node *x = rt;
        for (; s[0]; ++s){
                x = x->jump[s[0]-'A'];
                if (x->v && !x->vis){
                        x->vis = 1;
                        Q[top++] = x;
                }
        }
}
int ans, dfs_clock, cnt[2800000];
void dfs (Node *x){
        x->l = dfs_clock++;
        for (Edge*p = x->head; p; p = p->nxt){
                dfs (p->v);
        }
        x->r = dfs_clock-1;
}
void dfs2 (Node *x){
        if (x->v && x->vis == 1 && cnt[x->l] == cnt[x->r]){
                ++ans; return;
        }
        for (Edge*p = x->head; p; p = p->nxt){
                dfs2 (p->v);
        }
}
void init (){
        stp = mem2;
        bat = mem; rt = bat++; rt->clear ();
        rt->chf = 0;
}
int main(){
        int _; scanf ("%d", &_);
        for (int __ = 0; __ < _; ++__){
                int n; scanf ("%d", &n);
                init ();
                for (int i = 1; i <= n; ++i){
                        scanf ("%s", s);
                        transform (s, s2);
                        insert (s2, i);
                }
                build ();
                scanf ("%s", str);
                transform (str, str2);

                top = 0;
                find (str2);

                Node *x;
                for (int i = 0; i < top; ++i){
                        x = Q[i]->chf;
                        for (; x && x->vis < 2; x = x->chf)
                                x->vis ++;
                }

                dfs_clock = 0;
                dfs (rt);

                for (Node *i = mem; i != bat; ++i) cnt[i->l] = i->vis > 0;
                for (int i = 1; i < dfs_clock; ++i) cnt[i] += cnt[i-1];
                ans = 0;
                dfs2 (rt);
                printf ("%d\n", ans);
        }
        return 0;
}

#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/****head****/
const int Max_N = 9 + (int)5e5;
const int Max_BIT = 30;
const int BUFFER_SIZE = 10000;
namespace SegmentTree {
        struct Node {
                Node*ch[2];
                int cnt;
        } Tnull, *null=&Tnull, *rt[Max_N];
        Node*newNode(int w = 0) {
                static Node*buffer = 0, *cur;
                if(buffer == 0 || cur == buffer + BUFFER_SIZE) {
                        buffer = new Node[BUFFER_SIZE];
                        cur = buffer;
                }
                cur->cnt = w;
                cur->ch[0] = cur->ch[1] = null;
                return cur++;
        }
        void insert(Node*pre, Node*&x, int pos, int l = 1, int r = Max_N) {
                x = newNode(); *x = *pre; x->cnt++;
                if(l < r) {
                        int m = l + r >> 1;
                        if(pos <= m) insert(pre->ch[0], x->ch[0], pos, l, m);
                        else insert(pre->ch[1], x->ch[1], pos, m+1, r);
                }
        }
        int query(Node*x, Node*y, int qr, int l = 1, int r = Max_N) {
                //printf("%d %d %d %d\n", l, r, y->cnt, x->cnt);
                if(qr >= r) return y->cnt - x->cnt;
                int m = l + r >> 1;
                if(qr > m) return y->ch[0]->cnt - x->ch[0]->cnt + query(x->ch[1], y->ch[1], qr, m+1, r);
                else return query(x->ch[0], y->ch[0], qr, l, m);
        }
        int query_kth(Node*x, Node*y, int k, int l = 1, int r = Max_N) {
                if(l == r) return l;
                int m = l + r >> 1, cnt = y->ch[0]->cnt - x->ch[0]->cnt;
                if(cnt < k) return query_kth(x->ch[1], y->ch[1], k - cnt, m+1, r);
                else return query_kth(x->ch[0], y->ch[0], k, l, m);
        }
        void init() {
                null->cnt = 0;
                null->ch[0] = null->ch[1] = null;
                rt[0] = newNode();
        }
}
namespace Trie {
        const static int Max_M = 2;
        struct Node {
                Node*ch[Max_M];
                int cnt;
        } Tnull, *null=&Tnull, *rt[Max_N];
        Node*newNode(int w = 0) {
                static Node*buffer = 0, *cur;
                if(buffer == 0 || cur == buffer + BUFFER_SIZE) {
                        buffer = new Node[BUFFER_SIZE];
                        cur = buffer;
                }
                cur->cnt = w;
                memcpy(cur->ch, null->ch, sizeof cur->ch);
                return cur++;
        }
        void insert(Node*pre, Node*&x, int s, int bit) {
                x = newNode(); x->cnt = pre->cnt + 1;
                memcpy(x->ch, pre->ch, sizeof x->ch);
                if(bit >= 0) {
                        int go = s>>bit & 1;
                        insert(pre->ch[go], x->ch[go], s, bit - 1);
                }
        }
        int query(int l, int r, int x) {
                --l;
                Node*a = rt[l], *b = rt[r];
                int ret = 0;
                for(int i = Max_BIT; i >= 0; --i) {
                        int cur = x>>i & 1;
                        int cnt = b->ch[!cur]->cnt - a->ch[!cur]->cnt;
                        int go = cnt > 0 ? !cur : cur;
                        a = a->ch[go]; b = b->ch[go];
                        if(go) ret |= 1 << i;
                }
                return ret;
        }
        void init() {
                null->cnt = 0;
                for(int i = 0; i < Max_M; ++i) null->ch[i] = null;
                rt[0] = newNode();
        }
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        int nq, n = 0;
        Read(nq);
        Trie::init();
        SegmentTree::init();
        for(int op, l, r, x; nq--; ) {
                Read(op);
                if(!op) {
                        Read(x);
                        Trie::insert(Trie::rt[n], Trie::rt[n+1], x, Max_BIT);
                        SegmentTree::insert(SegmentTree::rt[n], SegmentTree::rt[n+1], x);
                        ++n;
                } else if(op == 1) {
                        Read(l); Read(r); Read(x);
                        printf("%d\n", Trie::query(l, r, x));
                } else if(op == 2) {
                        Read(x); n -= x;
                } else if(op == 3) {
                        Read(l); Read(r); Read(x);
                        printf("%d\n", query(SegmentTree::rt[l-1], SegmentTree::rt[r], x));
                } else {
                        Read(l); Read(r); Read(x);
                        printf("%d\n", query_kth(SegmentTree::rt[l-1], SegmentTree::rt[r], x));
                }
        }
        return 0;
}

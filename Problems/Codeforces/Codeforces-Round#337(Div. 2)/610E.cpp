/*
   other solution(without SegmentTree): http://codeforces.com/contest/610/submission/15151605
   */
#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
struct SegmentTree {
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
        const static int Max_N = 6000005;
        int ch[Max_N], n, sz, lazy[Max_N];
        void Down(int l, int r, int rt) {
                if(lazy[rt] != -1) {
                        ch[rt] = lazy[rt];
                        lazy[rt<<1] = lazy[rt];
                        lazy[rt<<1|1] = lazy[rt];
                        lazy[rt] = -1;
                }
        }
        void init(char*s, int l, int r, int rt) {
                lazy[rt] = -1;
                if(l == r) {
                        ch[rt] = s[l]; 
                        return;
                }
                int mid = l + r >> 1;
                init(s, lson); init(s, rson);
        }
        char query(int p, int l, int r, int rt) {
                if(lazy[rt] != -1) return lazy[rt];
                if(l == r) return ch[rt];

                Down(l, r, rt);
                int mid = l + r >> 1;
                if(p <= mid) return query(p, lson);
                else return query(p, rson);
        }
        void modify(int ql, int qr, char c, int l, int r, int rt) {
                if(l == r) ch[rt] = c;
                if(ql <= l && qr >= r) {
                        lazy[rt] = c; return;
                }
                Down(l, r, rt);
                int mid = l + r >> 1;
                if(ql <= mid) modify(ql, qr, c, lson);
                if(qr > mid) modify(ql, qr, c, rson);
        }

        //use
        void init(char *s, int n, int sz) {
                this->n = n;
                init(s, 0, n-1, 1);
        }
        void modify(int l, int r, char c) {
                modify(l, r, c, 0, n-1, 1);
        }
        char query(int p) {
                return query(p, 0, n-1, 1);
        }
}tree;
int _;
int n, m, sz;
char str[1<<18];
int sum[200], S;
map<int, int> has;
int type(char t1, char t2) {
        return (t1-'a') * sz + t2-'a';
}
void init(char*s) {
        S = 0;
        for(int i = 0; i < n-1; ++i) {
                if(s[i] == s[i+1]) ++S;
                else {
                        int t = type(s[i], s[i+1]);
                        has[i] = t;
                        ++sum[t];
                }
        }
        tree.init(s, n, sz);
}
void erase(map<int, int>::iterator it) {
        --sum[it->second];
        has.erase(it);
}
void add(int p, char t1, char t2) {
        has[p] = type(t1, t2);
        ++sum[type(t1, t2)];
}
void modify(int l, int r, char c) {
        int cnt = 0;
        auto it = has.lower_bound(l-1);
        while(it != has.end()) {
                if(it->first > r) break;
                if(it->first >= l && it->first < r) ++cnt;
                erase(it);
                it = has.lower_bound(l-1);
        }

        S += cnt;

        if(l) {
                char t1 = tree.query(l-1), t2 = tree.query(l);
                if(t1 == t2) --S;
                if(t1 == c) ++S;
                else add(l-1, t1, c);
        }

        if(r < n-1) {
                char t1 = tree.query(r), t2 = tree.query(r+1);
                if(t1 == t2) --S;
                if(t2 == c) ++S;
                else add(r, c, t2);
        }


        tree.modify(l, r, c);
}
int query(char *s) {
        int ret = S;
        for(int i = 1; i < sz; ++i) {
                for(int j = 0; j < i; ++j) {
                        ret += sum[type(s[i], s[j])];
                }
        }
        return ret;
}
int main() {
        //freopen("a.out","w",stdout);
        cin >> n >> m >> sz >> str;
        init(str);
        int t, l, r;
        while(m--) {
                scanf("%d", &t);
                if(t == 1) {
                        scanf("%d%d%s", &l, &r, str);
                        modify(l - 1, r - 1, str[0]);
                } else {
                        scanf("%s", str);
                        printf("%d\n", query(str) + 1);
                }
        }
        return 0;
}

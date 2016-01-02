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
int _;
struct seg {
        int l, r;
        int p;
};
pair<int, pair<int, int> > temp1, temp2;
bool operator == (const seg&x, const seg&y) {
        return x.l == y.l && x.r == y.r && x.p == y.p;
}
bool operator < (const seg&x, const seg&y) {
        return make_pair(x.r, make_pair(x.l, x.p)) < make_pair(y.r, make_pair(y.l, y.p));
}
bool cmp(seg x, seg y) {
        return make_pair(x.p, make_pair(x.l, x.r)) < make_pair(y.p, make_pair(y.l, y.r));
}
bool cmp2(seg x, seg y) {
        return x.l < y.l;
}
struct BIT{
        //index from 1 to n

#define lowbit(x) ((x)&(-x))
        const static int Max_N = 500005;
        int c[Max_N], n;

        //an[x] += d;
        void add(int x, int d) {
                while(x <= n) c[x] += d, x += lowbit(x);
        }

        //return the sum of an[1], an[2]...an[x]
        int sum(int x) {
                int ret = 0;
                while(x > 0) ret += c[x], x -= lowbit(x);
                return ret;
        }

        int sum(int l, int r) {
                return l > r ? 0 : sum(r) - sum(l-1);
        }
}bit;

vector<seg> H, C;
set<seg> st;
map<int, int> has;
int cope() {
        set<int> t1;
        map<int, int> t2;
        for(auto i : C) {
                t1.insert(i.p);
        }
        for(auto i : H) {
                t1.insert(i.l);
                t1.insert(i.r);
        }

        int t = 0;
        for(auto i : t1) t2[i] = ++t;

        for(auto&i : C) {
                i.p = t2[i.p];
        }
        for(auto&i : H) {
                i.l = t2[i.l];
                i.r = t2[i.r];
        }
        return t;
}
void erase() {
        auto it = has.find(st.begin()->p);
        if(it->second == 1) {
                bit.add(st.begin()->p, -1);
                has.erase(st.begin()->p);
        } else {
                --has[st.begin()->p];
        }
        st.erase(st.begin());
}
void add(const seg&t) {
        st.insert(t);
        auto it = has.find(t.p);
        if(it == has.end()) {
                bit.add(t.p, 1);
                has[t.p] = 1;
        } else {
                ++has[t.p];
        }
}
int query(int l, int r) {
        return bit.sum(l, r);
}
int main() {
        int n;
        while(cin >> n) {
                seg tmp;
                for(int i = 0, x1, y1, x2, y2; i < n; ++i) {
                        //cin >> x1 >> y1 >> x2 >> y2;
                        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                        if(x1 == x2) {
                                tmp.l = min(y1, y2);
                                tmp.r = max(y1, y2);
                                tmp.p = x1;
                                H.push_back(tmp);
                        } else {
                                tmp.l = min(x1, x2);
                                tmp.r = max(x1, x2);
                                tmp.p = y1;
                                C.push_back(tmp);
                        }
                }

                UNQ(H);
                UNQ(C);

                long long ans = 0;

                sort(H.begin(), H.end(), cmp);
                sort(C.begin(), C.end(), cmp);
                int pre = -(1 << 30), mx = pre;
                for(auto i : H) {
                        if(i.p != pre) {
                                mx = -(1 << 30);
                                pre = i.p;
                        }

                        if(i.l <= mx) ans -= min(mx, i.r) - i.l + 1;
                        ans += i.r - i.l + 1;
                        chmax(mx, i.r);
                }

                pre = -(1 << 30); mx = pre;
                for(auto i : C) {
                        if(i.p != pre) {
                                mx = -(1 << 30);
                                pre = i.p;
                        }

                        if(i.l <= mx) ans -= min(mx, i.r) - i.l + 1;
                        ans += i.r - i.l + 1;
                        chmax(mx, i.r);
                }

                bit.n = cope();

                sort(C.begin(), C.end(), cmp2);

                int idx = 0;
                mx = -(1 << 30);
                for(auto i : H) {
                        if(pre != i.p) {
                                for(; idx < SZ(C); ++idx) {
                                        if(C[idx].l > i.p) break;
                                        add(C[idx]);
                                }

                                while(!st.empty()) {
                                        if(st.begin()->r >= i.p) break;
                                        erase();
                                }

                                pre = i.p;
                                mx = -(1 << 30);
                        }

                        if(i.l > mx) ans -= query(i.l, i.r);
                        else if(i.r > mx) ans -= query(mx+1, i.r);
                        chmax(mx, i.r);
                }
                cout << ans;
        }
        return 0;
}

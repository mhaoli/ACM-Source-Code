#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
template<class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const long long mod = 7 + (int)1e9;
void add(int&a, int b) {
        a += b; if(a >= mod) a -= mod;
}
namespace small2 {
        int id;
        long long ans, L, R;
        int cnt;
        std::pair<long long, long long> temp;
        long long calc(long long t1, long long t2) {
                if(t1 % (t2<<1) == 0) return t1 + t2;
                if(t1 / (t2 << 1) * (t2 << 1) + t2 >= t1) 
                        return t1 / (t2 << 1) * (t2 << 1) + t2;
                return (t1 / (t2 << 1) + 1) * (t2 << 1) + t2;
        }
        long long transform(long long t) {
                if(t == 0) return 0;
                long long ret = 1;
                while(ret * 2 <= t) ret *= 2;
                return (ret << 1) - 1;
        }
        void update(long long&t1, int&t2, long long&s1, int&s2) {
                if(t1 == s1) add(t2, s2);
                if(t1 < s1) t1 = s1, t2 = s2;
        }
        long long max(long long t1, long long t2) {
                return t1 > t2 ? t1 : t2;
        }
        std::pair<long long, long long> solve(long long tl, long long tr, int _id) {
                L = tl; R = tr; id = _id;
                ans = 0; cnt = (R - L + 1) % mod;
                long long tmp, newAns, newCntTmp;
                int newCnt;
                for(long long i = 1; i <= R; i <<= 1) {
                        tmp = calc(L, i);
                        //out(i); 
                        //out(tmp);
                        if(tmp <= R) {
                                if(tmp + i - 1 <= R) {
                                        if(tmp-1 >= L) {
                                                //puts("a");
                                                newAns = (i << 1) - 1;
                                                newCnt = (tmp - max(tmp - i, L)) % mod * (i % mod) % mod;
                                                if(tmp - i >= L) newCnt = 0;
                                        }
                                        else {
                                                //puts("b");
                                                newAns = i - 1;
                                                newCnt = (i % mod) * ((i >> 1) % mod) % mod;
                                                //newCnt = (i >> 1) * (i >> 1);
                                        }
                                } else {
                                                //puts("c");
                                        newAns = transform(R - tmp);
                                        newCntTmp = (R - tmp - ((newAns+1) >> 1) + 1ll);
                                        if((newAns+1>>1) == newCntTmp) newCnt = (newCntTmp % mod) * ((newAns+1) % mod) % mod;
                                        else newCnt = (newCntTmp % mod) * (((newAns+1) >> 1) % mod) % mod;
                                }
                                update(ans, cnt, newAns, newCnt);
                        }
                        //out(ans);
                        //out(cnt);
                        //puts("\n");
                }
                cnt <<= 1;
                if(!ans) cnt = R - L + 1;
                temp.first = ans; temp.second = cnt;
                return temp;
        }
}
int DX[] = {0, 0, 1, -1}, DY[] = {1, -1, 0, 0};
namespace small1{
        long long L, R, ans;
        int top, id;
        long long num[303][303], cnt;
        int last[303][303], vis[303][303];
        std::pair<long long, long long> Q[303*303];
        std::pair<long long, long long> temp;
        bool ok(long long x, long long y, long long tar) {
                if(!(L <= x && x <= R && L <= y && y <= R)) return 0;
                return (x ^ y) == tar + 1;
        }
        void bfs() {
                top = 0;
                for(long long i = L; i <= R; ++i) {
                        Q[top].first = Q[top].second = i;
                        num[i-L][i-L] = 1;
                        vis[i-L][i-L] = id;
                        ++top;
                }
                long long tmp, x, y, tx, ty;
                for(int i = 0, d; i != top; ++i) {
                        x = Q[i].first; y = Q[i].second; tmp = x ^ y;
                        for(d = 0; d < 4; ++d) {
                                tx = Q[i].first + DX[d]; ty = Q[i].second + DY[d];
                                if(ok(tx, ty, tmp)) {
                                        if(vis[tx-L][ty-L] != id) {
                                                Q[top].first = tx; Q[top].second = ty; ++top;
                                                vis[tx-L][ty-L] = id;
                                        }
                                        if(last[tx-L][ty-L] == id) num[tx-L][ty-L] += num[x-L][y-L];
                                        else num[tx-L][ty-L] = num[x-L][y-L], last[tx-L][ty-L] = id;
                                }
                        }
                }
                ans = tmp; cnt = 0;
                for(int i = top-1; i >= 0; --i) {
                        if(ans != (Q[i].first ^ Q[i].second)) break;
                        cnt += num[Q[i].first-L][Q[i].second-L];
                }
        }
        std::pair<long long, long long> solve(long long tl, long long tr, int _id) {
                L = tl; R = tr; id = _id;
                bfs();
                temp.first = ans; temp.second = cnt;
                return temp;
        }
}

int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        int _; scanf("%d", &_);
        std::pair<long long, long long> ans, tmp;
        for(long long L, R; _--; ) {
                Read(L); Read(R);
                if(R - L <= -1) ans = small1::solve(L, R, _+1);
                else ans = small2::solve(L, R, _+1);
                printf("%lld %d\n", ans.first, (int)((ans.second+mod) % mod));
        }
        return 0;
}


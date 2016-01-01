#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
using namespace std;
const int mod = (int)1e9 + 7;
void add(int &a, int b) {
        a += b;
        if(a >= mod) a -= mod;
}

int _;
const int Max_N = (int)5e5 + 9;
int L, n, m;
char str[Max_N];
map<char, pair<int, int> > mp;
int ans;
int mix, miy, mxx, mxy;
int LX, LY, SX, SY;

bool ins(int x, int y) {
        return x >= LX && x <= SX && y >= LY && y <= SY;
}

void calc(int x, int y, int &fx, int &fy, bool flag) {
        mix = miy = mxx = mxy = 0;
        pair<int, int> tmp;
        int l, r, K;
        bool fg2 = true;
        for(int i = 0; i < L; ++i) {
                tmp = mp[str[i]];
                x += tmp.first;
                y += tmp.second;

                if(chmin(mix, x) && flag && fg2 && -mix + mxx + 1 <= n + 1) {
                        l = -miy; r = m - 1 - mxy;
                        if(l <= r) add(ans, (r - l + 1ll) * (i+1) % mod);
                }
                if(chmin(miy, y) && flag && fg2 && -miy + mxy + 1 <= m + 1) {
                        l = -mix; r = n - 1 - mxx;
                        if(l <= r) add(ans, (r - l + 1ll) * (i+1) % mod);
                }
                if(chmax(mxx, x) && flag && fg2 && -mix + mxx + 1 <= n + 1) {
                        l = -miy; r = m - mxy - 1;
                        if(l <= r) {
                                add(ans, (r - l + 1ll) * (i+1) % mod);
                                int tx = n-x-fx, tyr = min(r-fy, SY), tyl = max(l-fy, LY);
                                K = L + i + 1;
                                while(LX <= tx && tx <= SX && tyr >= LY && tyl <= SY) {
                                        add(ans, (min(tyr,SY) - tyl + 1ll) * K % mod);
                                        tx -= fx; tyr -= fy; tyl = max(tyl-fy, LY);
                                        add(K, L);
                                }
                        }
                }
                if(chmax(mxy, y) && flag && fg2 && -miy + mxy + 1 <= m + 1) {
                        l = -mix; r = n - 1 - mxx;
                        if(l <= r) {
                                add(ans, (r - l + 1ll) * (i+1) % mod);
                                int ty = m-y-fy, txr = min(r-fx, SX), txl = max(l-fx, LX);
                                K = L + i + 1;
                                while(LY <= ty && ty <= SY && txr >= LX && txl <= SX) {
                                        add(ans, (min(txr,SX) - txl + 1ll) * K % mod);
                                        ty -= fy; txr -= fx; txl = max(txl-fx, LX);
                                        add(K, L);
                                }
                        }
                }
        }
        fx = x; fy = y;
}
int main() {
        mp['U'] = make_pair(-1, 0);
        mp['D'] = make_pair(1, 0);
        mp['L'] = make_pair(0, -1);
        mp['R'] = make_pair(0, 1);

        while(std::cin >> L >> n >> m) {
                ans = 0;
                scanf("%s", str);
                int fx = Max_N, fy = Max_N;
                calc(0, 0, fx, fy, false);

                if(fx == 0 && fy == 0 && mxx-mix+1 <= n && mxy-miy+1 <= m) {
                        puts("-1");
                        continue;
                }

                if(fx < 0) {
                        fx = -fx;
                        for(int i = 0; i < L; ++i) {
                                if(str[i] == 'U') str[i] = 'D';
                                else if(str[i] == 'D') str[i] = 'U';
                        }
                        swap(mix, mxx);
                        mix = -mix;
                        mxx = -mxx;
                }
                if(fy < 0) {
                        fy = -fy;
                        for(int i = 0; i < L; ++i) {
                                if(str[i] == 'L') str[i] = 'R';
                                else if(str[i] == 'R') str[i] = 'L';
                        }
                        swap(miy, mxy);
                        miy = -miy;
                        mxy = -mxy;
                }

                LX = -mix; LY = -miy;
                SX = n - 1 - mxx; SY = m - 1 - mxy;

                calc(0, 0, fx, fy, true);
                printf("%d\n", ans);
        }
        return 0;
}


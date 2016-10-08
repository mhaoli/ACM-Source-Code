#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
int n;
vector<int> res;
int input(int a, int b, int c, int d) {
        printf("? %d %d %d %d\n", a, b, c, d);
        fflush(stdout);
        int ret;
        cin >> ret;
        return ret;
}
void output() {
        printf("!");
        for(int i : res) printf(" %d", i);
        puts("");
        fflush(stdout);
}
int find_cut(int&flag) {
        int cut = 0;
        for(int i = 0; i < 2; ++i) {
                int l = 1, r = n, mid, cnt;
                cut = 1 << 30;
                while(l <= r) {
                        mid = l + r >> 1;
                        cnt = flag ? input(1, 1, n, mid) : input(1, 1, mid, n);
                        if(cnt >= 1) {
                                chmin(cut, mid);
                                r = mid - 1;
                        } else {
                                l = mid + 1;
                        }
                }
                
                if(cut == n) cnt = 0;
                else cnt = flag ? input(1, cut+1, n, n) : input(cut+1, 1, n, n);
                if(cnt == 1) return cut;

                flag = 1;
        }
        assert(false);
}
void find_rect(int a1, int a2, int a3, int a4) {
        int a[4] = {a1, a2, a3, a4};
        int ans[4] = {0, 0, 1<<30, 1<<30};
        for(int i = 0; i < 2; ++i) {
                int l = a[i], r = a[i+2], mid, cnt, tmp;
                while(l <= r) {
                        mid = l + r >> 1;
                        tmp = a[i];
                        a[i] = mid;
                        cnt = input(a[0], a[1], a[2], a[3]);
                        a[i] = tmp;

                        if(cnt >= 1) {
                                chmax(ans[i], mid);
                                l = mid + 1;
                        } else r = mid - 1;
                }

                l = a[i]; r = a[i+2];

                while(l <= r) {
                        mid = l + r >> 1;
                        tmp = a[i+2];
                        a[i+2] = mid;
                        cnt = input(a[0], a[1], a[2], a[3]);
                        a[i+2] = tmp;

                        if(cnt >= 1) {
                                chmin(ans[i+2], mid);
                                r = mid - 1;
                        } else l = mid + 1;
                }
        }

        for(int i = 0; i < 4; ++i) {
                res.pb(ans[i]);
        }
}
int main() {
        cin >> n;
        int flag = 0, cut = find_cut(flag);
        if(!flag) {
                find_rect(1, 1, cut, n);
                find_rect(cut+1, 1, n, n);
        } else {
                find_rect(1, 1, n, cut);
                find_rect(1, cut+1, n, n);
        }
        output();
        return 0;
}

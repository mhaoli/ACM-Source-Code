/*
other: http://codeforces.com/contest/609/submission/14879612
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
int _;
int an[1<<18], bn[1<<18];
int ma[1<<18], mb[1<<18], idxa[1<<18], idxb[1<<18];
int ans, ansCnt1, ansCnt2;
vector<pair<int, int> > vec[2];
int n, m, k, S;
bool ok(long long s1, long long s2, int day) {
        return (s1 * ma[day] + s2 * mb[day]) <= S;
}
void check(long long s1, long long s2, int t1, int t2) {
        int res = 1 << 30, mid, l = 0, r = n - 1;
        while(l <= r) {
                mid = l + r >> 1;
                if(ok(s1, s2, mid)) {
                        chmin(res, mid);
                        r = mid - 1;
                } else {
                        l = mid + 1;
                }
        }

        if(chmin(ans, res)) {
                ansCnt1 = t1;
                ansCnt2 = t2;
        }
}
int main() {
        cin >> n >> m >> k >> S;
        for(int i = 0; i < n; ++i) {
                scanf("%d", an + i);
                ma[i] = an[i]; idxa[i] = i;
                if(i && chmin(ma[i], ma[i-1])) idxa[i] = idxa[i-1];
        }
        for(int i = 0; i < n; ++i) {
                scanf("%d", bn + i);
                mb[i] = bn[i]; idxb[i] = i;
                if(i && chmin(mb[i], mb[i-1])) idxb[i] = idxb[i-1];
        }

        for(int i = 0, t, c; i < m; ++i) {
                scanf("%d%d", &t, &c);
                vec[--t].push_back(make_pair(c, i));
        }
        sort(ALL(vec[0]));
        sort(ALL(vec[1]));

        ans = 1<<30;
        long long s1 = 0, s2 = 0;
        for(auto it : vec[1]) s2 += it.first;
        if(SZ(vec[1]) >= k) {
                check(s1, s2, 0, k);
        }
        int idx = SZ(vec[1]) - 1;
        for(int i = 0; i < SZ(vec[0]); ++i) {
                s1 += vec[0][i].first;
                while(i + idx + 2 > k && idx >= 0) {
                        s2 -= vec[1][idx].first;
                        --idx;
                }
                if(i + idx + 2 == k) check(s1, s2, i + 1, idx + 1);
        }

        if(ans == 1 << 30) puts("-1");
        else {
                printf("%d\n", ans + 1);
                int day[2];
                day[0] = idxa[ans] + 1;
                day[1] = idxb[ans] + 1;
                vector<pair<int, int> > res;
                for(int i = 0; i < ansCnt1; ++i) {
                        res.push_back(make_pair(vec[0][i].second + 1, day[0]));
                }
                for(int i = 0; i < ansCnt2; ++i) {
                        res.push_back(make_pair(vec[1][i].second + 1, day[1]));
                }

                for(auto it : res) {
                        printf("%d %d\n", it.first, it.second);
                }
        }
        return 0;
}

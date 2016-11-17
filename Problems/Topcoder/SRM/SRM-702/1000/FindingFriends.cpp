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
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define SZ(v) ((int)(v).size())
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define x first
#define y second
#define mp make_pair
#define pb push_back
//#define debug
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

class FindingFriends {
        public:
        int shortestDistance(int len, vector<int> init, int a, int b, int c, int d, int m);
};

#define lowbit(x) ((x)&(-x))

namespace seg {
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
        int v[1<<20], n;
        void init(int _n) {
                n = _n;
                memset(v, -1, (n<<2) * sizeof(v[0]));
        }
        void insert(int p, int x, int l = 0, int r = n-1, int rt = 1) {
                if(l == p && r == p) {
                        chmax(v[rt], x);
                } else {
                        int mid = l + r >> 1;
                        if(p <= mid) insert(p, x, lson);
                        else insert(p, x, rson);
                        chmax(v[rt], max(v[rt<<1], v[rt<<1|1]));
                }
        }
        int query_mx(int ql, int qr, int l = 0, int r = n-1, int rt = 1) {
                if(ql <= l && qr >= r) {
                        return v[rt];
                } else {
                        int mid = l + r >> 1, res = -1;
                        if(ql <= mid) chmax(res, query_mx(ql, qr, lson));
                        if(qr > mid) chmax(res, query_mx(ql, qr, rson));
                        return res;
                }
        }
}

vi an, bn, idx;
int M, K, L[1<<17], R[1<<17], tL[1<<17], nidx, n;

void calcL(vi &x, int*res) {
        seg::init(nidx);
        rep(i, 0, n) {
                int l = lower_bound(all(idx), x[i] - K) - idx.begin(), r = (upper_bound(all(idx), x[i] + K) - idx.begin()) - 1;
                res[i] = seg::query_mx(l, r);
                seg::insert(lower_bound(all(idx), x[i]) - idx.begin(), i);
        }
}

//[l,r)
bool find_good(int l, int r) {
        if(r - l < M) return false;
        int index = -1;
        for(int i = l, j = r-1; index == -1 && i <= j; ++i, --j) {
                if(L[i] < l && R[i] >= r) index = i;
                if(L[j] < l && R[j] >= r) index = j;
        }
        if(~index) return find_good(l, index) || find_good(index+1, r);
        return true;
}

bool check(int K) {
        ::K = K;
        calcL(an, L); calcL(bn, tL);
        rep(i, 0, n) R[i] = n - 1 - tL[n-1-i];
        return find_good(0, n);
}

int FindingFriends::shortestDistance(int len, vector<int> init, int a, int b, int c, int d, int m) {
        ::M = m; n = len;
        an = init; an.resize(len);
        rep(i, SZ(init), len) an[i] = (1ll * an[i-1] * a + 1ll * b * i + c) % d;

        bn = an; reverse(all(bn));
        idx = an; unq(idx); nidx = SZ(idx);

        int l = 0, r = 1e9, mid, res = -1;
        while(l <= r) {
                mid = l + r >> 1;
                if(check(mid)) r = mid - 1, res = mid;
                else l = mid + 1;
        }
        return res;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int len, vector<int> init, int a, int b, int c, int d, int m, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FindingFriends *instance = new FindingFriends();
    int __result = instance->shortestDistance(len, init, a, b, c, d, m);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_str(__expected) << endl;
        cout << "           Received: " << to_str(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int len = 6;
            int init[] = {
                8,
                1,
                10,
                2,
                9,
                7
            };
            int a = 12;
            int b = 34;
            int c = 56;
            int d = 78;
            int m = 2;
            int __expected = 1;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 1: {
            int len = 7;
            int init[] = {
                1
            };
            int a = 1;
            int b = 0;
            int c = 0;
            int d = 12345678;
            int m = 5;
            int __expected = 0;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 2: {
            int len = 12;
            int init[] = {
                0
            };
            int a = 1;
            int b = 0;
            int c = 1;
            int d = 6;
            int m = 3;
            int __expected = 0;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 3: {
            int len = 10;
            int init[] = {
                3,
                4,
                5
            };
            int a = 23;
            int b = 34;
            int c = 35;
            int d = 46;
            int m = 4;
            int __expected = 4;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 4: {
            int len = 2;
            int init[] = {
                0,
                1000000000
            };
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 1;
            int m = 2;
            int __expected = 1000000000;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 5: {
            int len = 5;
            int init[] = {
                1,
                2,
                1000,
                3,
                4
            };
            int a = 9;
            int b = 8;
            int c = 7;
            int d = 10;
            int m = 3;
            int __expected = 996;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }
        case 6: {
            int len = 100000;
            int init[] = {
                967948965
            };
            int a = 758179342;
            int b = 788391896;
            int c = 28648718;
            int d = 999999937;
            int m = 3;
            int __expected = 59543;
            return do_test(len, to_vector(init), a, b, c, d, m, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    
    bool mainProcess = true;
    set<int> testCases;
    for (int i = 1; i < argc; i++) {
        if ( string(argv[i]) == "-" ) {
            mainProcess = false;
        } else {
            testCases.insert( atoi(argv[i]) );
        }
    }
    if (testCases.size() == 0) {
        for (int i = 0; i < 7; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "FindingFriends (1000 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 7; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1479363497;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end

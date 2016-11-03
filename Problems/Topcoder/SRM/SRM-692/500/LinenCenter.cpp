#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;

const int mod = 1000000009;

class LinenCenter {
        public:
        typedef vector<int> poly;
        void add(int &a, int b) {
                a += b;
                if(a >= mod) a -= mod;
        }
        poly mul(poly a, poly b) {
                poly c(n + 1);
                for(int i = 0; i <= n; ++i) {
                        for(int j = 0; j <= n; ++j) if(i + j <= n){
                                add(c[i+j], (ll)a[i] * b[j] % mod);
                        }
                }
                return c;
        }
        poly polyPow(poly p, int n) {
                poly res((this->n) + 1);
                res[0] = 1;
                while(n) {
                        if(n & 1) res = mul(res, p);
                        p = mul(p, p);
                        n >>= 1;
                }
                return res;
        }
        int countStrings(string s, int n, int K) {
                this->n = n;
                this->L = SZ(s);
                vector<int> fail(L + 1);
                vector<vector<int> > jump(L, vector<int>(26));
                jump[0][s[0]-'a'] = 1;
                for(int i = 1; i < L; ++i) {
                        jump[i] = jump[fail[i]];
                        if(i < L) {
                                int c = s[i] - 'a';
                                fail[i+1] = jump[i][c];
                                jump[i][c] = i + 1;
                        }
                }
                vector<vector<int> > ways(n + 1, vector<int>(L+1));
                ways[0][0] = 1;
                for(int i = 0; i < n; ++i) {
                        for(int j = 0; j < L; ++j) {
                                for(int c = 0; c < 26; ++c) {
                                        add(ways[i+1][jump[j][c]], ways[i][j]);
                                }
                        }
                }
                poly base(n + 1);
                for(int i = 0; i < L; ++i) {
                        int state = i;
                        for(int j = 0; j < L-1 && state != L; ++j) {
                                state = jump[state][s[j]-'a'];
                        }
                        if(state != L) {
                                for(int j = 0; j <= n; ++j) {
                                        add(base[j], ways[j][i]);
                                }
                        }
                }
                poly dp = polyPow(base, K);
                int ans = 0, count;
                for(int i = 0; i <= n; ++i) {
                        count = 0;
                        for(int j = 0; j < L; ++j) {
                                add(count, ways[i][j]);
                        }
                        for(int j = 0; j + i <= n; ++j) {
                                add(ans, (ll)count * dp[j] % mod);
                        }
                }
                return ans;
        }
        int n, L;
};

// CUT begin
template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string S, int N, int K, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    LinenCenter *instance = new LinenCenter();
    int __result = instance->countStrings(S, N, K);
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
            string S = "xy";
            int N = 2;
            int K = 1;
            int __expected = 2079;
            return do_test(S, N, K, __expected, __no);
        }
        case 1: {
            string S = "q";
            int N = 2;
            int K = 1;
            int __expected = 1926;
            return do_test(S, N, K, __expected, __no);
        }
        case 2: {
            string S = "ababab";
            int N = 5;
            int K = 4;
            int __expected = 527166180;
            return do_test(S, N, K, __expected, __no);
        }
        case 3: {
            string S = "fgcdx";
            int N = 500;
            int K = 10;
            int __expected = 942389748;
            return do_test(S, N, K, __expected, __no);
        }
        case 4: {
            string S = "ghjhhhgjhjhgjhghghjhjg";
            int N = 8;
            int K = 10000000;
            int __expected = 618639712;
            return do_test(S, N, K, __expected, __no);
        }
        case 5: {
            string S = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfdlfpdlfdpflepflfldpflofpwpldlfpde";
            int N = 999;
            int K = 500000000;
            int __expected = 852730493;
            return do_test(S, N, K, __expected, __no);
        }
        case 6: {
            string S = "a";
            int N = 100;
            int K = 0;
            int __expected = 990669582;
            return do_test(S, N, K, __expected, __no);
        }
        case 7: {
            string S = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
            int N = 1000;
            int K = 1000000000;
            int __expected = 286425258;
            return do_test(S, N, K, __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
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
        for (int i = 0; i < 8; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "LinenCenter (500 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 8; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1467717735;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end

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

class BipartiteConstruction {
        public:
        void pb(int s, int e, int n = 1) {
                while(n--) {
                        ans.pb(s * (this->n) + e);
                }
        }
        vector<int> construct(int K) {
                ans.clear();
                if(!K) {
                        ans = vector<int>{2,1,0};
                        return ans;
                }

                n = 1;
                for(int a = K; a > 0; a /= 3, ++n);
                for(int i = 0; i < n; ++i) {
                        if(i < n-1) {
                                pb(i, i, 3);
                                pb(i+1, i);
                        }
                        pb(i, n-1, K%3);
                        K /= 3;
                }
                ans.pb(n);
                reverse(ALL(ans));
                return ans;
        }
        int n;
        vector<int> ans;
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> string to_str(vector<T> t) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < t.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_str(t[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int K, vector<int> __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    BipartiteConstruction *instance = new BipartiteConstruction();
    vector<int> __result = instance->construct(K);
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
            int K = 2;
            int __expected[] = {
                3,
                8,
                1,
                7,
                4,
                3,
                0
            };
            return do_test(K, to_vector(__expected), __no);
        }
        case 1: {
            int K = 5;
            int __expected[] = {
                1,
                0,
                0,
                0,
                0,
                0
            };
            return do_test(K, to_vector(__expected), __no);
        }
        case 2: {
            int K = 0;
            int __expected[] = {
                2,
                1,
                0
            };
            return do_test(K, to_vector(__expected), __no);
        }
        case 3: {
            int K = 2333333;
            int __expected[] = {
                20,
                93,
                195,
                195,
                211,
                87,
                114,
                369,
                390,
                216,
                195,
                305,
                17,
                370,
                356,
                308,
                150,
                263,
                20,
                153,
                331,
                79,
                344,
                108,
                114,
                257,
                245,
                289,
                211,
                388,
                388,
                359,
                293,
                263,
                219,
                131,
                201,
                293,
                279,
                204,
                97,
                367,
                90,
                279,
                308,
                324,
                323,
                359,
                338,
                63,
                26,
                318,
                218,
                226,
                164,
                361,
                276,
                388,
                343,
                149,
                17,
                336,
                88,
                161,
                76,
                237,
                136,
                278,
                302,
                107,
                271,
                15,
                382,
                45,
                338,
                264,
                78,
                150,
                220,
                341,
                180,
                20,
                252,
                94,
                114,
                161
            };
            return do_test(K, to_vector(__expected), __no);
        }

        // Your custom testcase goes here
        case 4:
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
        for (int i = 0; i < 4; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "BipartiteConstruction (600 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 4; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1467649580;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end

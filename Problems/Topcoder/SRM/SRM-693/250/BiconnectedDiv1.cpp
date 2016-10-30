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

class BiconnectedDiv1 {
        public:
        int minimize(vector<int> w1, vector<int> w2) {
                int n = SZ(w1) + 1;
                int sum = accumulate(ALL(w1), 0) + accumulate(ALL(w2), 0);
                vector<int> dp(n + 1);
                for(int i = 1; i < n-2; ++i) {
                        chmax(dp[i+1], dp[i]);
                        if(i < n-2) chmax(dp[i+1], dp[i] + w1[i]);
                        if(i < n-3) chmax(dp[i+2], dp[i] + w2[i]);
                }
                int mx = *max_element(ALL(dp));
                return sum - mx;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> w1, vector<int> w2, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    BiconnectedDiv1 *instance = new BiconnectedDiv1();
    int __result = instance->minimize(w1, w2);
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
            int w1[] = {
                    7,29,59,638,1280
            };
            int w2[] = {
                    3087,312,1,41
            };
            int __expected = 4504;
            return do_test(to_vector(w1), to_vector(w2), __expected, __no);
        }
        case 1: {
            int w1[] = {
                3,
                0,
                4
            };
            int w2[] = {
                1,
                2
            };
            int __expected = 10;
            return do_test(to_vector(w1), to_vector(w2), __expected, __no);
        }
        case 2: {
            int w1[] = {
                3,
                3,
                3,
                3
            };
            int w2[] = {
                3,
                6,
                3
            };
            int __expected = 18;
            return do_test(to_vector(w1), to_vector(w2), __expected, __no);
        }
        case 3: {
            int w1[] = {
                7243,
                7525,
                8467,
                6351,
                9453,
                8456,
                8175,
                5874,
                6869,
                7400,
                6438,
                8926,
                6876
            };
            int w2[] = {
                2642,
                1743,
                3546,
                4100,
                2788,
                3019,
                2678,
                1935,
                1790,
                2674,
                3775,
                1920
            };
            int __expected = 46729;
            return do_test(to_vector(w1), to_vector(w2), __expected, __no);
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
        cout << "BiconnectedDiv1 (250 Points)" << endl << endl;
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
        int T = time(NULL) - 1467895714;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end

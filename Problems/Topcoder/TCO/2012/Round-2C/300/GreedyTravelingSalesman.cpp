#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <string>
#include <utility>
#include <map>
#include <ctime>
#include <typeinfo>
#include <stack>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class GreedyTravelingSalesman {
    public:
    int n, d[55][55], v[55];
    int worstDistance(vector<string> v1, vector<string> v2, vector<string> v3, vector<string> v4) {
        clr (d, 0);
        n = sz(v1);
        add (v1, 1000); add (v2, 100); add (v3, 10); add (v4, 1);

        clr (v, 0);
        int ans = dfs (0);
        repf (i, 0, n-1) repf (j, 0, n-1) if (i != j){
            int tmp = d[i][j];
            d[i][j] = 1; clr (v, 0); chmax (ans, dfs (0));
            repf (k, 0, n-1){
                d[i][j] = max (d[i][k], 1); clr (v, 0); chmax (ans, dfs (0));
                d[i][j] = max (d[i][k] - 1, 1); clr (v, 0); chmax (ans, dfs (0));
                d[i][j] = min (d[i][k] + 1, 9999); clr (v, 0); chmax (ans, dfs (0));
            }
            d[i][j] = 9999; clr (v, 0); chmax (ans, dfs(0));
            d[i][j] = tmp;
        }
        return ans;
    }
    int dfs (int x){
        v[x] = 1;
        int last = -1;
        repf (i, 0, n-1) if (!v[i]){
            if (last == -1) last = i;
            else if (d[x][last] > d[x][i]) last = i;
        }

        if (last == -1) return 0;
        return d[x][last] + dfs (last);
    }
    void add (vs vec, int t){
        repf (i, 0, sz(vec)-1) repf (j, 0, sz(vec)-1) d[i][j] += (vec[i][j] - '0') * t;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> thousands, vector<string> hundreds, vector<string> tens, vector<string> ones, int __expected, int caseNo) {

    time_t startClock = clock();
    GreedyTravelingSalesman *instance = new GreedyTravelingSalesman();
    int __result = instance->worstDistance(thousands, hundreds, tens, ones);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string thousands[] = {
                "055",
                "505",
                "550"
            };
            string hundreds[] = {
                "000",
                "000",
                "000"
            };
            string tens[] = {
                "000",
                "000",
                "000"
            };
            string ones[] = {
                "000",
                "000",
                "000"
            };
            int __expected = 14999;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 1: {
            string thousands[] = {
                "018",
                "101",
                "990"
            };
            string hundreds[] = {
                "000",
                "000",
                "990"
            };
            string tens[] = {
                "000",
                "000",
                "990"
            };
            string ones[] = {
                "000",
                "000",
                "990"
            };
            int __expected = 17999;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 2: {
            string thousands[] = {
                "00888",
                "00999",
                "00099",
                "00009",
                "00000"
            };
            string hundreds[] = {
                "00000",
                "00999",
                "00099",
                "00009",
                "00000"
            };
            string tens[] = {
                "00000",
                "10999",
                "11099",
                "11109",
                "11110"
            };
            string ones[] = {
                "01000",
                "00999",
                "00099",
                "00009",
                "00000"
            };
            int __expected = 37997;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 3: {
            string thousands[] = {
                "000000",
                "000000",
                "990999",
                "999099",
                "999909",
                "999990"
            };
            string hundreds[] = {
                "000000",
                "000000",
                "990999",
                "999099",
                "999909",
                "999990"
            };
            string tens[] = {
                "000000",
                "000000",
                "990999",
                "999099",
                "999909",
                "999990"
            };
            string ones[] = {
                "011111",
                "101111",
                "990998",
                "999099",
                "999809",
                "999980"
            };
            int __expected = 39994;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 4: {
            string thousands[] = {
                "00",
                "00"
            };
            string hundreds[] = {
                "00",
                "00"
            };
            string tens[] = {
                "00",
                "00"
            };
            string ones[] = {
                "01",
                "10"
            };
            int __expected = 9999;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 5: {
            string thousands[] = {
                "0930",
                "1064",
                "0104",
                "1070"
            };
            string hundreds[] = {
                "0523",
                "1062",
                "6305",
                "0810"
            };
            string tens[] = {
                "0913",
                "0087",
                "3109",
                "1500"
            };
            string ones[] = {
                "0988",
                "2030",
                "6103",
                "5530"
            };
            int __expected = 14124;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 6: {
            string thousands[] = {
                "0329",
                "2036",
                "2502",
                "8970"
            };
            string hundreds[] = {
                "0860",
                "5007",
                "0404",
                "2770"
            };
            string tens[] = {
                "0111",
                "2087",
                "2009",
                "2670"
            };
            string ones[] = {
                "0644",
                "1094",
                "7703",
                "7550"
            };
            int __expected = 17785;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }
        case 7: {
            string thousands[] = {
                "098444156277392825243100607342",
                "200097656837707947798866622385",
                "290231695687128834848596019656",
                "407026565077650435591867333275",
                "843401002617957470339040852874",
                "349970591997218853400632158696",
                "419933000593511123878416328483",
                "696294503254214847884399055978",
                "641473980706392541888675375279",
                "936720077098054565078142449625",
                "203476089500970673371115103717",
                "511071853860312304204656816567",
                "347105714685052402147763392257",
                "125122220860203856679947732062",
                "121462979669220132944063071653",
                "928254504048223043681383050365",
                "502607124708785202536036594373",
                "793596587517012870906900400361",
                "712360060935346182084840996318",
                "761671392040312345002273366240",
                "812935320276738878200716148806",
                "228506917464479046839069740872",
                "755395721473881083093906155745",
                "192597782177910118061710039501",
                "721382839206745793530453013267",
                "076061794267810491768114700256",
                "857528357758085424372388710251",
                "173322450800442594145600093043",
                "761667192345925280210514410800",
                "521229810525064090301842864060"
            };
            string hundreds[] = {
                "098270581534726237580246464451",
                "108829763716747148395013332067",
                "830061279541380758964430491222",
                "431005058477371114834129826284",
                "601807314489142917339949914290",
                "330640126699733151822328009407",
                "851821069798846354566780680271",
                "648888407535627630663351884365",
                "051398660825518466890170447894",
                "631934884097214069747147155777",
                "768071219404930950472885304916",
                "924954163330715847561718395488",
                "189910033179029204426829479070",
                "960645776060701332402794474433",
                "244875842263950931884758650019",
                "528470075229660077692189442311",
                "752198673046476808978058423064",
                "899325998610605600525587569431",
                "965750123741820904031880230236",
                "121658852172052167706008445728",
                "556199378085507717770434101126",
                "864838242791403197110088834005",
                "593435343245223500439707230479",
                "622529771475840345624500421425",
                "503486612623475041392122088159",
                "518334626169655694269507400008",
                "967091631529233593414345370288",
                "300474162107271438029222620086",
                "010527691044447729596127150108",
                "742822904991333205419603623270"
            };
            string tens[] = {
                "029421809872798033258029765788",
                "705135039569772524273274786652",
                "170567418260893393020344098265",
                "401043354947659563658581268242",
                "746709065616595245635350557925",
                "739570024549618413776557843034",
                "184597012262496958610853505745",
                "689811400727818703807051112784",
                "894453010121164288965541305235",
                "323145029073008946088869964941",
                "834269564400729646453274750586",
                "538976762970745472202055589093",
                "765511399939087047106252621388",
                "906733295711605356366138410423",
                "107653940551700559321642810836",
                "428402693021051075533830345295",
                "386782660475155103347385287948",
                "936626025836194580089064628716",
                "718522629491464055045890912121",
                "370656945845300237607868352243",
                "951908186614186444840337711498",
                "535178875249889835014025850038",
                "505970047705717604298603983975",
                "484398304612602344941130624527",
                "048342694079170795987835013947",
                "860331019262176299872846206272",
                "549663926438975145562538360932",
                "329735455392841851511474791078",
                "711755200061373546828858448100",
                "778808866574640894148527759780"
            };
            string ones[] = {
                "050738147930236727719964251439",
                "804492562859282318664226330103",
                "610197568193830684654773608216",
                "279000416545607314567843085541",
                "782201171759873927350740022455",
                "043370803444176631019883186675",
                "566092086050401228622782761449",
                "469598907881602996036692882305",
                "116923500417992303845370254124",
                "796876115092839169954790509461",
                "783836410405270687557924090071",
                "095144151150833738671751747749",
                "354474585664039135189964700948",
                "328968176148004939648962631420",
                "829651915384290848347221555092",
                "170980383407813034573738951375",
                "728655435703349509419725538350",
                "121896684176286430427852435647",
                "315710894574884960021671476788",
                "592177839598531202003634382961",
                "876587919610157913350259498196",
                "505517243779897451333006271744",
                "618607877753891664471800511372",
                "826358757330233811836040764274",
                "206641252044293046424432092833",
                "704519364781672964993499009545",
                "624793571592392775564426440338",
                "571938479010503551295729304078",
                "077967252884369103891335711508",
                "870185204806328841827105139840"
            };
            int __expected = 39896;
            return do_test(to_vector(thousands), to_vector(hundreds), to_vector(tens), to_vector(ones), __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "GreedyTravelingSalesman (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398259451;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

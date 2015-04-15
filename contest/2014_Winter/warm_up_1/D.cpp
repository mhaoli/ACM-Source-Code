/*
 * Author:  Plumrain
 * Created Time:  2014-02-09 16:27
 * File Name: D.cpp
 */
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

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, -1, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

struct pro{
    string s;
    vector<int> nam;
    void CLR(){
        s.clear(); nam.clear();
    }
    void TST(){
        cout << "nam: " << s << endl;
        for (int i = 0; i < sz(nam)-1; ++ i) tst(nam[i]);
        cout << nam[sz(nam)-1] << endl;
    }
    bool operator == (pro a){
        if (s != a.s) return 0;
        int n = sz(nam);
        if (n != sz(a.nam)) return 0;
        for (int i = 0; i < n; ++ i)
            if (nam[i] != a.nam[i] && nam[i] != 3 && a.nam[i] != 3) return 0;
        return 1;
    }
};

map<string, int> mp, var;
pro an[1005];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    mp.clear(); var.clear();
    mp["int"] = 0; mp["string"] = 1; mp["double"] = 2; mp["T"] = 3;
    int n, m, k;
    while (scanf ("%d", &n) != EOF){
        string s, tmp;
        getline(cin, s);
        for (int i = 0; i < n; ++ i){
            getline(cin, s);
            an[i].CLR(); tmp.clear(); 
            bool u1 = 0, u2 = 0;
            int slen = sz(s);
            for (int j = 0; j < slen; ++ j){
                if (s[j] == ' ' || s[j] == '(' || s[j] == ')' || s[j] == ','){
                    if (!sz(tmp)) continue;

                    if (!u1 && !u2) u1 = 1;
                    else if (u1 && !u2) u2 = 1, an[i].s = tmp;
                    else an[i].nam.pb (mp[tmp]);
                    tmp.clear();
                }
                else tmp.pb (s[j]);
            }
        }

        //for (int i = 0; i < n; ++ i) an[i].TST();
//
        scanf ("%d", &m);
        getline(cin, s);
        for (int i = 0; i < m; ++ i){
            getline(cin, s);
            s += " ";
            int slen = sz(s), idx = -1;
            tmp.clear();
            for (int j = 0; j < slen; ++ j){
                if (s[j] == ' '){
                    if (!sz(tmp)) continue;

                    if (idx == -1) idx = mp[tmp];
                    else var[tmp] = idx;
                    tmp.clear();
                }
                else tmp.pb (s[j]);
            }
        }

        scanf ("%d", &k);
        getline(cin, s);
        pro temp;
        for (int i = 0; i < k; ++ i){
            getline(cin, s);
            int slen = sz(s), u = 0;
            tmp.clear(); temp.nam.clear();
            for (int j = 0; j < slen; ++ j){
                if (s[j] == ' ' || s[j] == '(' || s[j] == ')' || s[j] == ','){
                    if (!sz(tmp)) continue;

                    if (!u) u = 1, temp.s = tmp;
                    else temp.nam.pb (var[tmp]);
                    tmp.clear();
                }
                else tmp.pb (s[j]);
            }

            //out (i); temp.TST();
            int ans = 0;
            //if (!i) out (temp.s), out (an[1].s), out (temp.s == an[1].s);
            //if (!i){
                //for (int i = 0; i < sz(an[0].nam); ++ i) tst (an[0].nam[i]);
                //cout << endl;
            //}
            for (int j = 0; j < n; ++ j) if (temp == an[j]) ++ ans;
            printf ("%d\n", ans);
        }
    }
    return 0;
}

/*
 * Author:  OpenRainbow
 * Created Time:  2014/8/19 15:52:37
 * File Name: 1005.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

string s;

bool ok (char c){
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

string dfs (int l, int r){
    //tst (l), tst (r), tst (s[l]), out (s[r]);
    if (l > r) return "";
    int num = 1;
    string res;
    if (s[l] == '('){
        int pos = l + 1, cnt = 1;
        while (pos <= r){
            if (s[pos] == '(') ++ cnt;
            else if (s[pos] == ')') -- cnt;
            if (!cnt) break;
            ++ pos;
        }
        string tmp = dfs (l + 1, pos - 1);
        ++ pos;
        if (pos <= r && s[pos] == '*'){
            num = 0;
            while (pos <= r && s[pos] >= '0' && s[pos] <= '9') num = num * 10 + s[pos] - '0';
        }
        rep (i, 0, num-1) res += tmp;
        return res + dfs (pos, r);
    }
    else{
        int pos = l;
        vs cls;
        string name, id, son, tmp, cls_tmp;

        while (pos <= r && ok (s[pos])) name.pb (s[pos++]);
        while (1){
            if (pos <= r && s[pos] == '#'){
                ++ pos;
                while (pos <= r && ok (s[pos])) id.pb (s[pos++]);
            }

            if (pos <= r && s[pos] == '.'){
                ++ pos; cls_tmp.clear();
                while (pos <= r && ok (s[pos])) cls_tmp.pb (s[pos++]);
                cls.pb (cls_tmp);
            }

            if (pos <= r && s[pos] == '*'){
                ++ pos;
                num = 0;
                while (pos <= r && s[pos] >= '0' && s[pos] <= '9') num = num * 10 + s[pos++] - '0';
            }

            if (pos > r || s[pos] == '>'){
                ++ pos;
                tmp = "<" + name;
                if (sz (id)){
                    tmp += " id="; tmp.pb ('\"'); tmp += id; tmp.pb ('\"');
                }
                if (sz (cls)){
                    tmp += " class="; tmp.pb ('\"');
                    rep (i, 0, sz (cls)-1){
                        if (i) tmp.pb (' ');
                        tmp += cls[i];
                    }
                    tmp.pb ('\"');
                }

                tmp += ">" + dfs (pos, r) + "</" + name + ">";

                res.clear();
                rep (i, 0, num-1) res += tmp;
                break;
            }
        }
        return res;
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        cin >> s;
        cout << dfs (0, sz(s)-1) << endl;
    }
    return 0;
}

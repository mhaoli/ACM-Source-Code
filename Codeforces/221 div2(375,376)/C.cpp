/*
 * Author:  Plumrain
 * Created Time:  2013-12-25 14:09
 * File Name: C.cpp
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

#define clr0(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

bool del[4];
string temp = "1689";
map<int, string> mp;

void gao(string s)
{
    stringstream stm(s);
    int num; stm >> num;
    int yu = num % 7;
    if (!mp.count(yu)) mp[yu] = s;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    mp.clear();
    string tt = "1689";
    gao(tt);
    while (next_permutation(tt.begin(), tt.end())) gao(tt);

    string s;
    while (cin >> s){
        clr0 (del);
        string ss; ss.clear();
        int n = sz(s), cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (s[i] == '0'){
                ++ cnt; continue;
            }
            bool ok = 0;
            for (int j = 0; j < 4; ++ j) if (s[i] == temp[j] && !del[j]){
                del[j] = 1; ok = 1;
            }
            if (!ok) ss.pb (s[i]);
        }

        int len = sz(ss);
        if (!len){
            ss = mp[0];
            for (int i = 0; i < cnt; ++ i) ss.pb ('0');
            cout << ss << endl;
            continue;
        }
        for (int i = 0; i < cnt; ++ i) ss.pb ('0');
        len = sz(ss);
        int flag = 0;
        for (int i = 0; i < len; ++ i)
            flag = (flag*10 + ss[i] - '0')  % 7;
        flag = flag * 10000 % 7;
        ss += mp[(7 - flag) % 7];
        cout << ss << endl;
    }
    return 0;
}

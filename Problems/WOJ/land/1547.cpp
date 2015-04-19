/*
 * Author:  Plumrain
 * Created Time:  2014-04-08 23:03
 * File Name: xiaosaiA.cpp
 * data : 10^6个L, up为奇为偶都测
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
#include <bitset>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 1000005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

char s[maxn];
bool ans[maxn];
map<char, int> cha;
int an[maxn], ma[maxn], mi[maxn], two[maxn];

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    cha['R'] = 1; cha['L'] = -1;
    two[0] = 1;
    repf (i, 1, 23) two[i] = two[i-1] * 2;

    int n, up, cas = 0;
    while (scanf ("%d%d", &n, &up) != EOF){
        scanf ("%s", s+1);

        /* for test */
        //printf ("Case %d:\n", ++ cas);
        //bitset<25> myset(up);
        //cout << n << " " << up << endl;
        //cout << "up:" << myset << endl;
        //repf (i, 1, n) printf ("%c", s[i]);
        //cout << endl;

        if(s[n] == 'L'){
            printf ("0\n"); continue;
        }

        clr (an, 0); clr (ma, 0); clr (mi, 127);
        repf (i, 1, n) an[i] = an[i-1] + cha[s[i]], ma[i] = max (an[i], ma[i-1]), mi[i] = min (an[i], mi[i-1]);
        
        //repf (i, 1, n) tst (i), out (an[i]);
//
        clr (ans, 0);
        if (!(up & 1)){
            int fir = n, last = 0;
            repf (i, 1, n){
                if (an[i] < 0) chmin (fir, i);
                if (s[i] == 'L') last = i - 1;

                if (((an[i]&up)|1) > ma[i-1]) ans[i] = 1;
            }
            repf (i, 1, last) ans[i] = 0;
            repf (i, fir, n-1) ans[i] = 0;
        }
        else{
            int num = 1, tmp = up, bitnum = 0;
            while (tmp & 1) tmp >>= 1, num <<= 1, ++ bitnum;
            tmp |= 1;
            while (tmp < up) tmp <<= 1;

            //out (num); out (up); out (tmp); out (bitnum);
//
            int last = 0, fir = n;
            repf (i, 1, n-1){
                int cnt = an[i] & up; cnt >>= bitnum; cnt |= 1; cnt <<= bitnum;
                int diff = an[n] - an[i];
                //if (i == 557329) out (diff), out (diff + (an[i]&up)), out (cnt);
                //if (i >= 557329) tst (i), out (s[i]);

                if (diff +  (an[i]&up) < cnt){
                    if (diff + (an[i]&up) > ma[i-1] && ma[n-1] < ma[n]) ans[i] = 1;
                }
                else{
                    //if (i == 1) tst1 (b);
                    //if (i == n-1){
                        //tst (cnt); out (ma[i-1]);
                        //out (an[i]&up);
                        //out (an[n]);
                        //out ((an[n]-an[i])%num);
                        //out (tmp);
                    //}
                    int tt1 = (an[i]&up) + (diff%num);
                    if (cnt > ma[i-1] && (tt1 == cnt || tt1 == (cnt-num))) ans[i] = 1;
                }

                int ttmp = (an[i-1] & up) & (two[bitnum]-1);
                if (ttmp == 0 && s[i] == 'L') last = i - 1;
                if (an[i] < 0) chmin (fir, i);
            }
            repf (i, 1, last) ans[i] = 0;
            repf (i, fir, n-1) ans[i] = 0;
        }

        if (ma[n] > ma[n-1] && mi[n] >= 0) ans[n] = 1;
        else ans[n] = 0;

        int ans_num = 0;
        repf (i, 1, n) if (ans[i]) ++ ans_num;
        printf ("%d", ans_num);
        repf (i, 1, n) if (ans[i]) printf (" %d", i);
        printf ("\n");
    }
    return 0;
}

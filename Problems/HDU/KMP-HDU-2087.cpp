/*
 * Author:  Plumrain
 * Created Time:  2014-03-10 11:00
 * File Name: KMP-HDU-2087.cpp
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

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

char s1[2000], s2[2000];
int f[2000];

void getfail (char *s, int *f){
    int n = strlen (s);
    f[0] = 0; f[1] = 0;
    repf (i, 1, n-1){
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        if (s[i+1] != s[j+1])
            f[i+1] = s[i] == s[j] ? j+1 : 0;
        else f[i+1] = f[i];
    }
}

int find (char *s1, char *s2, int *f){
    int n = strlen (s1), m = strlen (s2);
    getfail (s2, f);
    int j = 0, ret = 0;
    repf (i, 0, n-1){
        while (j && s1[i] != s2[j]) j = f[j];
        if (s1[i] == s2[j]) j ++;
        if (j == m){
            ++ ret; j = 0;
        }
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%s%s", s1, s2) != EOF && s1[0] != '#')
        printf ("%d\n", find(s1, s2, f));
    return 0;
}

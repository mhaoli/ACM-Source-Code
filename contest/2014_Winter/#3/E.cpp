/*
 * Author:  Plumrain
 * Created Time:  2014-02-12 15:36
 * File Name: E.cpp
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
#define clrs(x,y) memset(x, y, sizeof(x))
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

int n, m, temp;
int mp[100];
int d[100][150][150];
vector<pii > vec[17000];

void init()
{
    for (int i = 0; i < (1<<(m+m)); ++ i) vec[i].clear();
    for (int i = 0; i < (1<<m); ++ i)
        for (int j = 0; j < (1<<m); ++ j){
            for (int k = 0; k < m-1; ++ k)
                if (!(i & (1<<k)) && !(i & (1<<(k+1)))){
                    int sta = (i | (1 << k)) | (1 << (k+1));
                    sta = (sta << m) | j;
                    vec[(i<<m)|j].pb (sta);
                }

            for (int k = 0; k < m; ++ k)
                if (!(i & (1<<k)) && !(j & (1<<k))){
                    int sta = i | (1 << k);
                    sta = (sta << m) | (j | (1 << k));
                    vec[(i<<m)|j].pb (sta);
                }
        }
}

bool ok(int j, int k, int t)
{
    if (
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    while (scanf ("%d%d". &n, &m) != EOF){
        init();

        string s;
        for (int i = 0; i < n; ++ i){
            cin >> s;
            int sta = 0;
            for (int j = 0; j < m; ++ j) if (s[j] == '*') sta |= (1 << j);
            mp[i] = sta;
        }

        clrs (d, 127);
        temp = d[0];
        d[0][mp[0]][mp[1]] = 0;
        for (int i = 0; i < (1<<m); ++ i)
            for (int j = 0; j < (1<<m); ++ j){
                int num = sz(vec[(i<<m)|j]);

                for (int k = 0; k < num; ++ k){
                    int sta = vec[(i<<m)|j][k];
                    d[0][sta/(1<<m)][sta%(1<<m)] = min(d[0][sta/(1<<m)][sta%(1<<m)], d[i][j] + 1);
                }
            }

        for (int i = 1; i < n; ++ i){
            for (int j = 0; j < (1<<m); ++ j){
                bool u = 0;
                for (int t = 0; t < m-1; ++ t) 
                    if (!(j & (1<<t)) && !(j & (1<<(t+1)))) u = 1;
                if (u) continue; 

                for (int k = 0; k < (1<<m); ++ k) if (d[i-1][j][k] < temp){
                    if (i < n-1) d[i][k][mp[i+1]] = min(d[i][k][l], d[i-1][j][k]);

                    bool tt = 0;
                    for (int t = 0; t < m; ++ t) if (!(j & (1<<t)) && !(k & (1<<t))) tt = 1;

                    for (int l = 0; l < (1<<m); ++ l){
                        for (int t = 0; t < m; ++ t) if (!(j & (1<<t)) && !(k & (1<<t))){
                            if (i < n-1 && !(l & (1<<t)))
                        }
                    }
                }

            }
        }
    }
    return 0;
}

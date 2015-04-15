/*
 * Author:  Plumrain
 * Created Time:  2013-12-18 23:44
 * File Name: B.cpp
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

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define ALL(t) t.begin(),t.end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2147483647;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> pii;
typedef long long int64;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int64 two[100];
int a[100005];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    two[0] = 1;
    for (int i = 1; i < 63; ++ i)
        two[i] = two[i-1] * 2;

    string s;
    while (cin >> s){
        int n = s.size();
        for (int i = 0; i < n; ++ i)
            a[i] = s[i] - '0';

        int num = 1;
        int64 ans = 1;
        for (int i = 1; i < n; ++ i){
            if (a[i] + a[i-1] == 9)
                num ++;
            else{
                if (num > 1 && num & 1) ans *= (num/2+1);
                num = 1;
            }
        }
        if (num > 1 && num & 1) ans *= (num/2+1);
        cout << ans << endl;
    }
    
    return 0;
}

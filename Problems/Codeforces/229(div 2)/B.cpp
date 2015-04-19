/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: B.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<cctype>
#include<ctime>
#include<utility>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int N = 100005;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}

int an[N], bn[N];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        int64 sum = 0;
        for (int i = 0; i < n; ++ i) scanf ("%d", &an[i]);
        for (int i = 0; i < n; ++ i) scanf ("%d", &bn[i]);

        for (int i = 0; i < n; ++ i){
            if (an[i]*2 < bn[i]) -- sum;
            else if (bn[i] == 1) -- sum;
            else{
                int64 tmp = bn[i] / 2;
                if (bn[i] & 1) sum += tmp * (tmp + 1);
                else sum += tmp * tmp;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

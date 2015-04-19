/*
 * Author:  Plumrain
 * Created Time:  2013-12-13 22:02
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>
//#include <list>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//#include <bitset>
//#include <cctype>
//#include <ctime>
//#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
//#define PB push_back
//#define SZ(v) ((int)(v).size())
//#define INF 999999999999
//#define zero(x) (((x)>0?(x):-(x))<eps)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int maxint = 2147483647;
//
//typedef vector<int> VI;
//typedef vector<string> VS;
//typedef vector<double> VD;
//typedef pair<int, int> pii;
//typedef long long int64;
//
//inline int Mymod (int a, int b) {int x=a%b; if(x<0) x+=b; return x;}
//
int num[100];
int k;
string s;

bool gao()
{
    k *= 2;
    for (int i = 1; i < 10; ++ i)
        if (num[i] > k) return 0;
    return 1;
}

int main()
{
    //    freopen("a.in","r",stdin);
    //    freopen("a.out","w",stdout);
    //    std::ios::sync_with_stdio(false);
    while (scanf ("%d", &k) != EOF){
        CLR (num);
        for (int i = 0; i < 4; ++ i){
            s.clear();
            cin >> s;
            int sz = s.size();
            for (int j = 0; j < sz; ++ j)
                if (s[j] >= '1' && s[j] <= '9')
                    ++ num[s[j]-'0'];
        }
        if (gao()) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}

/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/2 14:04:31
 * File Name: 1318.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
typedef long long ll;
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
long long ans[] = {
        0,2,3,4,6,6,12,15,20,30,30,60,42,84,105,140,210,210,420,280,420,420,840,504,1260,1155,1540,2310,2520,4620,3080,5460,4620,9240,5544,13860,9240,16380,15015,27720,30030,32760,60060,40040,60060,60060,120120,72072,180180,120120,180180,180180,360360,180180,360360,360360,471240,510510,556920,1021020,720720,1141140,1021020,2042040,1225224,3063060,2042040,3423420,3063060,6126120,3423420,6846840,6126120,6846840,6846840,8953560,9699690,12252240,19399380,13693680,19399380,19399380,38798760,23279256,58198140,38798760,58198140,58198140,116396280,58198140,116396280,116396280,140900760,116396280,157477320,140900760,232792560,157477320,232792560,232792560,281801520,446185740,314954640,446185740,446185740,892371480,535422888,1338557220,892371480,1338557220,1338557220,2677114440,1338557220,2677114440,2677114440,2677114440,2677114440,3375492120,2677114440,5354228880,3375492120,5354228880,5354228880,5354228880,5354228880,6750984240,5354228880,7216569360,6750984240,8172244080,12939386460,13385572200,13831757940,13385572200,25878772920,15527263752,38818159380,25878772920,41495273820,38818159380,77636318760,41495273820,82990547640,77636318760,82990547640,82990547640,82990547640,82990547640,155272637520,82990547640,165981095280,155272637520,165981095280,165981095280,165981095280,165981095280,209280511440,165981095280,232908956280,209280511440,388181593800,401120980260,414952738200,401120980260,414952738200,802241960520,481345176312,1203362940780,802241960520,1203362940780,1203362940780,2406725881560,1203362940780,2406725881560,2406725881560,2406725881560,2406725881560,2872543794120,2406725881560,4813451763120,2872543794120,4813451763120,4813451763120,4813451763120,4813451763120,5745087588240,4813451763120,6141300525360,5745087588240,7220177644680,6141300525360,12033629407800,7220177644680,12033629407800,12033629407800,12033629407800,12033629407800,14440355289360,14841476269620,24067258815600,14841476269620,24067258815600,29682952539240,24067258815600,44524428808860,29682952539240,44524428808860,44524428808860,89048857617720,44524428808860,89048857617720,89048857617720,98675761143960,89048857617720,103489212907080,98675761143960,178097715235440,103489212907080,178097715235440,178097715235440,197351522287920,178097715235440,206978425814160,197351522287920,222622144044300,206978425814160,267146572853160,222622144044300,445244288088600,267146572853160,445244288088600,445244288088600,493378805719800,445244288088600,534293145706320,493378805719800,890488576177200,534293145706320,890488576177200,890488576177200,986757611439600,890488576177200,1034892129070800,1217001054108840,1034892129070800,1825501581163260,1335732864265800,1914550438780980,1825501581163260,3651003162326520
};
int main()
{
        for(int n; scanf("%d", &n), n; ) cout<<ans[n-1]<<endl;
        return 0;
}

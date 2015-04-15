//by PlumRain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

int64 ans[12][12];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	clr(ans);
	ans[2][2] = 0;
	ans[2][3] = 4;
	ans[2][4] = 16;
	ans[2][5] = 16;
	ans[2][6] = 16;
	ans[2][7] = 16;
	ans[2][8] = 25216;
	ans[2][9] = 186496;
	ans[2][10] = 1275136;
	ans[2][11] = 26676736;
	ans[2][12] = 106510336;
	ans[3][2] = 1;
	ans[3][3] = 3;
	ans[3][4] = 3;
	ans[3][5] = 27;
	ans[3][6] = 27;
	ans[3][7] = 27;
	ans[3][8] = 30267;
	ans[3][9] = 151227;
	ans[3][10] = 2691387;
	ans[3][11] = 31721787;
	ans[3][12] = 430889787;
	ans[5][2] = 1;
	ans[5][3] = 5;
	ans[5][4] = 5;
	ans[5][5] = 5;
	ans[5][6] = 245;
	ans[5][7] = 3125;
	ans[5][8] = 23285;
	ans[5][9] = 345845;
	ans[5][10] = 708725;
	ans[5][11] = 18852725;
	ans[5][12] = 18852725;
	ans[7][2] = 1;
	ans[7][3] = 1;
	ans[7][4] = 7;
	ans[7][5] = 103;
	ans[7][6] = 583;
	ans[7][7] = 2023;
	ans[7][8] = 17143;
	ans[7][9] = 339703;
	ans[7][10] = 1428343;
	ans[7][11] = 8685943;
	ans[7][12] = 208269943;
	ans[11][2] = 1;
	ans[11][3] = 5;
	ans[11][4] = 11;
	ans[11][5] = 11;
	ans[11][6] = 131;
	ans[11][7] = 2291;
	ans[11][8] = 2291;
	ans[11][9] = 244211;
	ans[11][10] = 244211;
	ans[11][11] = 244211;
	ans[11][12] = 119994611;
	bool xxx = false;
	int p,m;
	while( scanf( "%d%d" , &p , &m ) != EOF ){
		if( xxx )
			printf( "\n" );
		else
			xxx = true;
		printf( "%lld\n" , ans[p][m] );
	}
	return 0;
}

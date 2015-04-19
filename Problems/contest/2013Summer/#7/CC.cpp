//by plum rain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <ctime>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<':'<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

string an[15][4100];

void Data_Initial()
{
	an[2][0].clear();
	an[2][1].clear();
	an[2][2].clear();
	an[2][3].clear();
	an[2][0] = "00";
	an[2][1] = "01";
	an[2][2] = "10";
	an[2][3] = "11";
	an[3][0].clear();
	an[3][0] = "000";
	an[3][1].clear();
	an[3][1] = "101";
	an[3][2].clear();
	an[3][2] = "010";
	an[3][3].clear();
	an[3][3] = "100";
	an[3][4].clear();
	an[3][4] = "111";
	an[3][5].clear();
	an[3][5] = "001";
	an[3][6].clear();
	an[3][6] = "011";
	an[3][7].clear();
	an[3][7] = "110";	
	int time = 0 , i = 0 , j = 0;
	while( time < 16 ){
		an[4][time].clear();
		an[4][time++] = an[2][i] + an[2][j];
		i = (i+1) % 4 ; j = (j+1) % 4;
		if( i == 0 )
			j = (j+1) % 4;
	}
	time = 0 , i = 0 , j = 0;
	while( time < 32 ){
		an[5][time].clear();
		an[5][time++] = an[2][i] + an[3][j];
		i = (i+1) % 4 ; j = (j+1) % 8;
		if( i == 0 )
			j = (j+1) % 8;
	}
	time = 0 , i = 0 , j = 0;
	int k = 0 , add = 0;
	while( time < 64 ){
		an[6][time].clear();
		an[6][time++] = an[2][i] + an[2][j] + an[2][k];
		i = (i+1) % 4 ; j = (j+1) % 4 ; k = (k+1) % 4;
		add ++;
		if( i == 0 && add < 4 ){
			k = (k+1) % 4;
		}
		if( i == 0 && add == 4 ){
			j = (j+1) % 4;
			add = 0;
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int n;
	Data_Initial();
	bool blank = false;
	while( scanf( "%d" , &n ) != EOF && n ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		if( n == 2 ){
			cout << an[2][0] << endl << an[2][1] << endl << an[2][2] << endl << an[2][3] << endl;
			continue;
		}
		if( n == 3 ){
			rep( i , 8 )
				cout << an[3][i] << endl;
			continue;
		}
		if( n == 4 ){
			for( int i = 0 , j = 3 ; i < 4 ; i ++ , j -- )
				cout << an[2][j] << an[2][i] << endl;
			for( int i = 0 , j = 2 ; j >= 0 ; i ++ , j -- )
				cout << an[2][j] << an[2][i] << endl;
			cout << an[2][3] << an[2][3] << endl;
			continue;
		}
		if( n == 5 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 32 ){
				time ++;
				cout << an[2][i] << an[3][j] << endl;
				i = (i+1) % 4 ; j = (j+1) % 8 ;
				if( i == 0 ){
					j = (j+1) % 8;
				}
			}
			continue;	
		}	
		if( n == 6 ){
			int time = 0 , i = 0 , j = 0 , k = 1 , add = 0;
			while( time < 64 ){
				time ++;
				cout << an[2][i] << an[2][j] << an[2][k] << endl;
				i = (i+1) % 4 ; j = (j+1) % 4 ; k = (k+1) % 4;
				add ++;
				if(i == 0 && add < 4){
					k = (k+1) % 4; 
				}
				if( i == 0 && add == 4 ){
					add = 0;
					j = (j+1) % 4;
				}
			}
		}
		if( n == 7 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 128 ){
				time ++;
				cout << an[4][i] << an[3][j] << endl;
				i = (i+1) % 16 ; j = (j+1) % 8;
				if( i == 0 )
					j = (j+1) % 8;
			}
			continue;
		}
		if( n == 8 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 256 ){
				time ++;
				cout << an[4][i] << an[4][j] << endl;
				i = (i+1) % 16 ; j = (j+1) % 16;
				if( i == 0 )
					j = (j+1) % 16;
			}
			continue;
		}
		if( n == 9 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 512 ){
				time ++;
				cout << an[4][i] << an[5][j] << endl;
				i = (i+1) % 16 ; j = (j+1) % 32;
				if( i == 0 )
					j = (j+1) % 32;
			}
		}
		if( n == 10 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 1024 ){
				time ++;
				cout << an[4][i] << an[6][j] << endl;
				i = (i+1) % 16 ; j = (j+1) % 64;
				if( i == 0 )
					j = (j+1) % 64;
			}
		}
		if( n == 11 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 2048 ){
				time ++;
				cout << an[5][i] << an[6][j] << endl;
				i = (i+1) % 32 ; j = (j+1) % 64;
				if( i == 0 )
					j = (j+1) % 64;
			}
		}
		if( n == 12 ){
			int time = 0 , i = 0 , j = 0;
			while( time < 4096 ){
				time ++;
				cout << an[6][i] << an[6][j] << endl;
				i = (i+1) % 64 ; j = (j+1) % 64;
				if( i == 0 )
					j = (j+1) % 64;
			}
		}
	} 
	return 0;
}

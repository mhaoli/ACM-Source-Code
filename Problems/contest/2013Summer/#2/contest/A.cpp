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
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;

typedef vector<int> VI;  
typedef vector<string> VS;  
typedef vector<double> VD;  
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 2005;

int ssn[N];

void Devide_Two( bool x , int an[] , int &len )
{
		int cnt = an[0] % 2;
		ssn[0] = an[0] / 2;
		for( int i = 1 ; i < len ; i ++ ){
			int a = cnt * 10 + an[i];
			cnt = a % 2;
			ssn[i] = a / 2;
		}
		if( ssn[0] == 0 ){
			memset(an,0,sizeof(an));
			for( int i = 1 ; i < len ; i ++ )
				an[i-1] = ssn[i];
			len --;
		}
		else{
			memset(an,0,sizeof(an));
			for( int i = 0 ; i < len ; i ++ )
				an[i] = ssn[i];
		}
}

bool if_odd( int an[] , int len )
{
	if( an[len-1] % 2 )
		return true;
	else
		return false;
}

void Del_One( int s[] , int len )
{
	if( s[len-1] )
		s[len-1] -= 1;
	else{
		s[len-1] = 9;
		bool xxx = true;
		int	flag = len - 2;
		while(xxx){
			if( s[flag] ){
				xxx = false;
				s[flag] -= 1;
			}
			else{
				s[flag] = 9;
			}
			flag --;
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	scanf( "%d" , &n );
	string s1;
   	int	an1[N];
	for( int test = 0 ; test < n ; test ++ ){
		s1.clear();
		cin >> s1;
		int len1 = s1.size();
		for( int j = 0 ; j < len1 ; j ++ ){
			an1[j] = s1[j] - '0';
		}
		if( if_odd(an1,len1 ) ){
			Devide_Two(1,an1,len1);
		}
		else{
			Devide_Two(0,an1,len1);
			Del_One(an1,len1);
			if( !if_odd(an1,len1) )
				Del_One(an1,len1);
		}
		if( test != 0 )
			printf( "\n" );
		for( int i = 0 ; i < len1 ; i ++ )
			printf( "%d" , an1[i] );
		printf( "\n" );
	}
	return 0;
}

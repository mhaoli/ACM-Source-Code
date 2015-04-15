//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
int sum,len;
int ans[1000000];
bool cut[10],ans_cut[10];
char num[10];

int Sum()
{
	int a = 1 , b = 0;
	for( int i = 1 ; i < len ; i ++ ){
		if( !cut[i] )
			a ++;
		else{
			int j = i - 1 , c = 0;
			while( a > 0 ){
				b += (num[j]-'0') * pow(10,c);
				a --;
				j --;
				c ++;
			}
			a ++;
		}
	}
	int c = 0 , j = len-1;
	while( a > 0 ){
		b += (num[j]-'0') * pow(10,c);
		a --;
		j --;
		c ++;
	}
	return b;
}

void DFS( int x )
{	
	cut[x] = true;
	int a = Sum();
	if( a <= sum ){
		ans[a] ++;
		bool xx = false;
		for( int i = sum ; i > a ; i -- )
			if( ans[i] > 0 ){
				xx = true;
				break;
			}
		if( !xx ){
			for( int i = 0 ; i < len ; i ++ )
				ans_cut[i] = cut[i];
		}
		/*if( a == 43 )
		  for( int i = 0 ; i < len ; i ++ ){
		  out(i);
		  out(cut[i]);
		  }*/
	}
	for( int i = x+1 ; i < len ; i ++ )
		DFS(i);
	cut[x] = false;	
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	while( cin >> sum >> num ){
		if( !sum && num[0] == '0' )
			break;
		memset( ans , 0 , sizeof(ans) );
		memset( cut , false , sizeof(cut) );
		len = strlen(num);
		DFS(0);
		/*for( int i = 1 ; i <= sum ; i ++ ){
		  out(i);
		  out(ans[i]);
		  }*/
		for( int i = sum ; i >= 0 ; i -- ){
			if( ans[i] ){
				if( ans[i] == 1 ){
					cout << i;
					for( int j = 0 ; j < len ; j ++ ){
						if( ans_cut[j] )
							cout << " ";
						int xxxx = num[j] - '0';
						cout << xxxx;
					}	
					cout << endl;
				}
				else{
					cout << "rejected" << endl;
				}
				break;
			}
			if( i == 0 )
				cout << "error" << endl;
		}
	}
	return 0;
}

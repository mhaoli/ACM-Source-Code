//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
string s,t;
int main()
{
	//freopen("a.in","r",stdin);
	while( cin >> s >> t ){
		int ans = -1;
		bool xxx = true;
		for( int i = 0 ; i < s.size() ; i ++ ){
			bool xx = false;
			for( int j = ans+1 ; j < t.size() ; j ++ ){
				if( s[i] == t[j] ){
					ans = j;
					xx = true;
					break;
				}
			}
			if( !xx ){
				xxx = false;
				break;
			}
		}
		if( xxx )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

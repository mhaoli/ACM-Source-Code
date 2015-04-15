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

class SE{
	public:
		string s;
}an[105];
int all;


bool cmp( SE a , SE b )
{	
	return a.s < b.s;
}

int main()
{
	//freopen("a.in","r",stdin);
	int test;
	cin >> test;
	while (test--){
		all = 0;
		int n;
		cin >> n;
		string current;
		vector<string> dic;
		for( int i = 0 ; i < n ; i ++ ){
			cin >> current;
			dic.push_back(current);
		}
		int ans = 60;	
		while( ans >= 3 ){
			bool xxxx = false;
			for( int i = 0 ; i <= 60-ans ; i ++ ){
				int x = 1;
				string s1(dic[0],i,ans);
				while( x < n ){
					bool xxx = false;
					for( int j = 0 ; j <= 60-ans ; j ++ ){
						string s2(dic[x],j,ans);
						if( s1 == s2 ){
							xxx = true;
							break;
						}
					}
					if( !xxx )
						break;
					else
						x ++;
				}
				if( x == n ){
					xxxx = true;
					an[all++].s = s1;
				}
			}
			if( xxxx ){
				break;
			}
			ans --;
		}
		if( ans == 2 )
			cout << "no significant commonalities" << endl;
		else{
			sort(an,an+all,cmp);
			cout << an[0].s <<endl;
		}	
	}
	return 0;
}

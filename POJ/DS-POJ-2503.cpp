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
const int maxx = 100005;

class DIC{
	public:
		string ann , bnn;
}dic[maxx];

int all;

int BinarySearch( string x )
{
	int left = 0 , right = all - 1;
	while( left <= right ){
		int mid = ( left + right ) / 2;
		if( dic[mid].bnn < x )
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

bool cmp( DIC x , DIC y )
{
	return x.bnn <= y.bnn;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	all = 0;
	char xxx[15];
	char x;
	cin >> dic[all].ann;
	scanf( "%c" , &x );
	while( x == ' ' ){
		cin >> dic[all++].bnn;
		cin >> dic[all].ann;
		scanf( "%c" , &x );
	}
	sort(dic,dic+all,cmp);
	string xx;
	xx = dic[all].ann;
	int poss = BinarySearch(xx);
	if( xx == dic[poss].bnn )
		cout << dic[poss].ann << endl;
	else
		cout << "eh" << endl;
	while( cin >> xx ){
		int pos = BinarySearch(xx);
		if( xx == dic[pos].bnn )
			cout << dic[pos].ann << endl;
		else
			cout << "eh" << endl;
	}	
	return 0;
}

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
const int maxx = 10005;

int an[maxx];

class SqList {
	public:
		int r[maxx];
		int length;
}L;						//定义一个线性表用于存放数据元素

void HeapAdjust ( int s, int m)
{								//已知L.r[s...m]中记录除L.r[s]外均满足堆的定义，本函数用于使L.r[s...m]成为一个大顶堆
	int e = L.r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j] < L.r[j + 1])
			++j;
		if (e >= L.r[j])
			break;
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = e;
}

void HeapSort ( int *HeapSortan , int left, int right )	//如果要排序的数组是an[5]，则HeapSort(an,0,4);
{														//将原数组中的元素存入新定义的类L中
	for( int i = left ; i <= right ; i ++ )
		L.r[i] = HeapSortan[i];
	L.length = right - left;							//开始堆排，先将线性表构造成堆
	for (int i = L.length/2 ; i >= 0 ; i--)
		HeapAdjust (i, L.length);
	for (int i = L.length ; i > 0; i--){				//将大顶堆的顶记录和最后一个记录相互交换
		int e = L.r[0];
		L.r[0] = L.r[i];
		L.r[i] = e;
		HeapAdjust (0, i - 1);
	}
	for( int i = left ; i <= right ; i ++ )
		HeapSortan[i] = L.r[i];
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	while( cin >> n ){
		if( n == -5 )
			break;
		memset( an , 0 , sizeof(an) );
		for( int i = 0 ; i < n ; i ++ )
			cin >> an[i];
		HeapSort(an,0,n-1);
		int mid = n / 2;
		cout << an[mid] << endl;
	}
	return 0;
}

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
const int maxx = 500005;

int an[maxx];

int64 Merge (int *is1, int low, int mid, int high)
{
	int is2[maxx];	
	int i = low, j = mid + 1, k = low;
	int64 count = 0;
	while (i <= mid && j <= high)
		if (is1[i] <= is1[j])	
			is2[k++] = is1[i++];
		else {
			is2[k++] = is1[j++];
			count += j - k;		
		}
	while (i <= mid)
		is2[k++] = is1[i++];
	while (j <= high)
		is2[k++] = is1[j++];
	for (i = low; i <= high; i++)	
		is1[i] = is2[i];
	return count;
}

int64 MergeSort (int *is1, int a, int b)	
{
	if (a < b){
		int mid = (a + b) / 2;
		int64 count = 0;
		count += MergeSort (is1, a, mid);
		count += MergeSort (is1, mid + 1, b);
		count += Merge (is1, a, mid, b);
		return count;
	}
	return 0;
}

int main()
{
	//freopen("a.in","r",stdin);
	int n;
	while( cin >> n ){
		if( !n )
			break;
		for( int i = 0 ; i < n ; i ++ )
			cin >> an[i];		
		int64 ans = MergeSort(an,0,n-1);
		cout << ans << endl;
	}	
	return 0;
}

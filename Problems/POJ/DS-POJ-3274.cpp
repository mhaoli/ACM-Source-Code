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
const int prime = 99991;
const int N = 100005;
const int K = 35;

vector<int> hash[prime+1];
vector<int> HashTable;
int sum[N][K];
int n, k;

bool Compare(int a, int b)
{
	if (HashTable[a] != HashTable[b])
		return false;
	int x = sum[a][0] - sum[b][0];
	for (int i = 0; i < k; i ++)
		if (x != sum[a][i]-sum[b][i])
			return false;
	return true;
}

void Initial(int idx, int a)
{	
	int64 key = 0;
	if (!idx){
		for (int i = k-1; i >= 0; i --){
			sum[idx][i] = a & 1;
			key += sum[idx][i] - sum[idx][k-1];
			a >>= 1;
		}
	}
	else{
		for (int i = k-1; i >= 0; i --){
			sum[idx][i] = (a & 1) + sum[idx-1][i];
			key += sum[idx][i] - sum[idx][k-1];
			a >>= 1;
		}	
	}
	key = (key%prime + prime) % prime;
	hash[key].push_back(idx);
	HashTable.push_back(key);
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	memset(sum, 0, sizeof(sum));
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i ++){
		int a;
		scanf ("%d", &a);
		Initial (i,a);
	}
	/*for (int i = 0; i < n; i ++){
		for (int j = 0; j < k; j ++)
			cout << sum[i][j] << " ";
		cout << endl;	
	}*/
	int ans = 0;
	for (int i = 0; i < n; i ++){
		int key = HashTable[i];
		if (key == 0){
			int x = sum[i][0];
			for (int j = 1; j < k; j ++){
				if (x != sum[i][j])
					break;
				if (j == k-1)
					ans = max (ans, i+1);
			}
		}
		for (int j = hash[key].size()-1; j >= 0; j --){
			if (Compare(i,hash[key][j])){
				ans = max (ans, hash[key][j]-i);
				break;
			}	
		}	
	}
	printf ("%d\n", ans);
	return 0;
}

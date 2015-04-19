/*
 * Author:  Plumrain
 * Created Time:  2014-04-07 01:34
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int64, int64> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

//归并排序求逆序数
//求逆序数的对象是数组an[],函数返回值是逆序数
//比较平均的时间复杂度O(nlogn)
//空间复杂度O(n)
const int maxn = (1<<20) + 5;

int64 ans;
int is2[maxn];	
int a[maxn], f[25];
pii num[maxn<<2], sum[25];

pii Merge (int *is1, int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	int64 count1 = 0, count2 = 0;
	while (i <= mid && j <= high)
		if (is1[i] <= is1[j]){	// 此处为稳定排序的关键，不能用小于
            if (is1[i] == is1[j]) count2 ++;
			is2[k++] = is1[i++];
        }
		else {
			is2[k++] = is1[j++];
			count1 += j - k;		// 每当后段的数组元素提前时，记录提前的距离
		}
	while (i <= mid)
		is2[k++] = is1[i++];
	while (j <= high)
		is2[k++] = is1[j++];
	for (i = low; i <= high; i++)	// 写回原数组
		is1[i] = is2[i];
    //tst (low), tst (mid), tst (high), tst (count1), out (count2);
	return mp (count1, 1LL * (mid-low+1) * (high-mid) - count2 - count1);
}

void MergeSort (int *is1, int a, int b, int rt)	// 下标，例如对于数组int is[5]排序的话，全部排序的调用为MergeSort(0,4)
{
    //out (rt);
	if (a < b) {
		int mid = (a + b) / 2;
		MergeSort (is1, a, mid, rt<<1);
		MergeSort (is1, mid + 1, b, rt<<1|1);
        
        //num[rt].x = num[rt<<1].x + num[rt<<1|1].x;
        //num[rt].y = num[rt<<1].y + num[rt<<1|1].y;
//
		pii tmp = Merge (is1, a, mid, b);
        //tst (rt), tst (tmp.x), out (tmp.y);
        num[rt].x = tmp.x; num[rt].y = tmp.y;
        return ;
	}
    num[rt].x = num[rt].y = 0;
    return ;
}

void ask_sum(int len, int rt, int n){
    if (len == n) return;

    ask_sum (len+1, rt<<1, n);
    ask_sum (len+1, rt<<1|1, n);

    ans += num[rt].x;
    sum[len].x += num[rt].x;
    sum[len].y += num[rt].y;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        int tot = 1 << n;
        repf (i, 0, tot-1) scanf ("%d", a+i);
        MergeSort (a, 0, tot-1, 1);

        //repf (i, 0, tot<<2) tst (i), tst (num[i].x), out (num[i].y);
//
        ans = 0;
        repf (i, 0, 22) sum[i].x = sum[i].y = 0;
        ask_sum (0, 1, n); 

        //repf (i, 0, n) tst (i), tst (sum[i].x), out (sum[i].y);
//
        int q, tmp;
        clr (f, 0);
        scanf ("%d", &q);
        while (q --){
            scanf ("%d", &tmp);
            repf (i, 1, tmp){
                int idx = n - i;
                if (f[idx]) ans += sum[idx].x - sum[idx].y;
                else ans += sum[idx].y - sum[idx].x;
                f[idx] ^= 1;
            }
            printf ("%lld\n", ans);
        }
    }
    return 0;
}

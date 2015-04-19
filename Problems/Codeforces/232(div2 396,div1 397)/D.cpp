/*
 * Author:  Plumrain
 * Created Time:  2014-02-27 11:20
 * File Name: D.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int64 SPE = 46856248255981;    /*强伪素数*/
const int MT = 5;                   /*prm[]的元素个数，也即是需要测试的底的个数*/    

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int64 prm[5] = {2, 3, 7, 61, 24251};

struct frac{
	LL num,den;
    frac( LL a, LL b ) {
        num = a, den = b; 
    }
    frac() {}
};

double fabs(double x){
	return x>0?x:-x;
}

int gcd(LL a,LL b){
	LL t;
	if (a<0)
		a=-a;
	if (b<0)
		b=-b;
	if (!b)
		return a;
	while (t=a%b)
		a=b,b=t;
	return b;
}

void simplify(frac& f){
	LL t;
	if (t=gcd(f.num,f.den))
		f.num/=t,f.den/=t;
	else
		f.den=1;
}

frac f(LL n,LL d,LL s=1){
	frac ret;
	if (d<0)
		ret.num=-n,ret.den=-d;
	else
		ret.num=n,ret.den=d;
	if (s)
		simplify(ret);
	return ret;
}

frac convert(double x){
	frac ret;
	for (ret.den=1;fabs(x-LL(x))>1e-10;ret.den*=10,x*=10);
	ret.num=(LL)x;
	simplify(ret);
	return ret;
}

LL fraqcmp(frac a,frac b){
	LL g1=gcd(a.den,b.den),g2=gcd(a.num,b.num);
	if (!g1||!g2)
		return 0;
	return b.den/g1*(a.num/g2)-a.den/g1*(b.num/g2);
}

frac add(frac a,frac b){
	LL g1=gcd(a.den,b.den),g2,t;
	if (!g1)
		return f(1,0,0);
	t=b.den/g1*a.num+a.den/g1*b.num;
	g2=gcd(g1,t);
	return f(t/g2,a.den/g1*(b.den/g2),0);
}

frac sub(frac a,frac b){
	return add(a,f(-b.num,b.den,0));
}

frac mul(frac a,frac b){
	LL t1=gcd(a.den,b.num),t2=gcd(a.num,b.den);
	if (!t1||!t2)
		return f(1,1,0);
	return f(a.num/t2*(b.num/t1),a.den/t1*(b.den/t2),0);
}

frac div(frac a,frac b){
	return mul(a,f(b.den,b.num,0));
}

//要判断n是不是质数时，调用语句为miller_rabin(n, MT);
int64 mul_mod(int64 p, int64 q, int64 mod)
{
     int64 ret = 0;
     p %= mod;
     while (q){
         if (q & 1){
             ret += p;
             if (ret >= mod) ret -= mod;
         }
         p <<= 1; q >>= 1;
         if (p >= mod) p -= mod;
     }
     return ret;
}

int64 pow_mod(int64 p, int64 n, int64 mod)
{
    int64 ret = 1;
    p %= mod;
    while (n > 0){
        if (n & 1) ret = mul_mod(ret, p, mod);
        n >>= 1;
        p = mul_mod(p, p, mod);
    }
    return ret;
}

bool Wintess(int64 aa, int64 n, int64 mod)      /*是以aa为底的伪质数返回0,是合数返回1*/
{
    int t = 0;
    while ((n & 1) == 0){               /*n = d * 2^t; n = d;*/
        n >>= 1;
        ++ t;
    }

    int64 x = pow_mod(aa, n, mod), y;
    while (t --){
        y = mul_mod (x, x, mod);
        if (y == 1 && x != 1 && x != mod-1) return 1;
        x = y;
    }
    return (y != 1);
}

bool miller_rabin(int64 n, int tim)
{
    if (n == 2) return true;
    if (n == 1 || (n & 1) == 0 || n == SPE) return false;

    for (int i = 0; i < tim; ++ i){
        int64 aa = prm[i];           /*也可以用随机化的aa，在前面写srand(time(NULL));在这里写int64 aa=rand()%(n-1)+1;*/
        if (aa == n) return true;
        if (Wintess(aa, n-1, n)) return false;
    }
    return true;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T --){
        int64 n;
        cin >> n;
        int64 l = n, r = n+1;
        while (!miller_rabin(l, MT)) -- l;
        while (!miller_rabin(r, MT)) ++ r;

        frac ans;
        ans = sub (frac(1, 2), frac(1, l));
        ans = add (ans, frac(n-l+1, l*r));
        cout << ans.num << "/" << ans.den << endl;
    }
    return 0;
}

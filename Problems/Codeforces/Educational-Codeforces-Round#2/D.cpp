#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
const long double pi = 2 * acos(0.0);
const long double eps = 1e-6;
struct pnt {
        long double x, y;
};
struct ccl {
        pnt o; long double r;
        ccl() { }
        ccl(pnt a, long double b) : o(a), r(b) { }
        //specific
        void rd() {
                double x, y, _r;
                scanf("%lf%lf%lf", &x, &y, &_r);
                o.x = x; o.y = y; r = _r;
        }
        friend ostream& operator<<(ostream& out,ccl& p) {
                out<<"("<<p.o.x<<","<<p.o.y<<","<<p.r<<")";
                return out;
        }
};
long double dis(pnt a, pnt b) {
        return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
long double circleIntersectionArea(ccl c1, ccl c2) {  
        if(c1.r < c2.r - eps) swap(c1, c2);
        long double d = dis(c1.o, c2.o);
        if(d >= (c1.r + c2.r) * (c1.r + c2.r) + eps) return 0;
        if(d <= (c1.r-c2.r) * (c1.r-c2.r) + eps) return pi * c2.r * c2.r;

        long double dd = sqrt(d), ret = 0;
        long double t = acos((c1.r*c1.r - c2.r*c2.r + d) / 2 / c1.r / dd);
        ret += t * c1.r * c1.r;
        long double tmp = c1.r * sin(t);
        ret -= sqrt(c1.r*c1.r - tmp*tmp) * tmp;
        t = acos((c2.r*c2.r - c1.r*c1.r + d) / 2 / c2.r / dd);
        if(t > pi/2) {
                ret += t * c2.r * c2.r;
                tmp = c2.r * sin(t);
                ret += sqrt(c2.r*c2.r - tmp*tmp) * tmp;
        } else {
                ret += t * c2.r * c2.r;
                tmp = c2.r * sin(t);
                ret -= sqrt(c2.r*c2.r - tmp*tmp) * tmp;
        }
        return (double)ret;
}
int main() {
        ccl c1, c2;
        c1.rd(); c2.rd();
        printf("%.15f", (double)circleIntersectionArea(c1, c2));
        return 0;
}

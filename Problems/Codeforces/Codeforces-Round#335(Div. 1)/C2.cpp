#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
//vector
const double eps = 1e-4;
int dcmp(double x) {
    if(fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}
struct pkt{
        int x,y;
        //构造函数 
        pkt():x(0.0),y(0.0){}
        pkt(int px, int py):x(px),y(py){}
        pkt(int x1, int y1, int x2, int y2):x(x2-x1),y(y2-y1){}
        //向量运算 
        pkt operator+(const pkt&p) {
                return pkt(x+p.x,y+p.y);
        }
        pkt operator-(const pkt&p) {
                return pkt(x-p.x,y-p.y);
        }
        pkt operator-() {
                return pkt(-x,-y);
        }
        long long operator*(const pkt& p) { //点积 
                return 1ll*x*p.x + 1ll*y*p.y;
        }
        pkt operator*(const int p) { //数量积 
                return pkt(x*p, y*p);
        }
        long long operator^(const pkt& p) { //叉积 
                return 1ll*x*p.y-1ll*y*p.x;
        }
        pkt& operator+=(const pkt& p) {
                x+=p.x;
                y+=p.y;
                return *this;
        }
        pkt& operator-=(const pkt& p) {
                x-=p.x;
                y-=p.y;
                return *this;
        }
        pkt& operator*=(const int p) { //数量积 
                x*=p;
                y*=p;
                return *this;
        }
        bool operator==(const pkt &p)const {
                //return x == p.x && y == p.y;
                return !dcmp(x-p.x) && !dcmp(y-p.y);
        }

        double length() {                       //向量模 
                return sqrt(1ll*x*x + 1ll*y*y + 0.0);
        }

        friend ostream& operator<<(ostream& out,pkt& p) {
                out<<"("<<p.x<<","<<p.y<<")";
                return out;
        }
};
typedef pkt pnt;        //point
bool cmp(const pkt&a, const pkt&b) {
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
}
int _;
bool GetLineIntersection(pnt p, pkt v, pnt q, pkt w, double&t1, double&t2) { //计算直线交点res
        if((v^w) == 0)return 0;
        pkt u = p - q;
        double t = 1.0 * (w^u) / (v^w);
        t1 = p.x + v.x * t;
        t2 = p.y + v.y * t;
        return 1;
}
//bool onSegment(pnt p, pnt a, pnt b)  //判断点是否在线段ab上
    //return dcmp((a-p)*(b-p)) <= 0 && !dcmp((a-p)^(b-p));
//}
bool onSegment(double t1, double t2, double t3, double t4, double t5, double t6) { //判断点是否在线段ab上
        return dcmp((t3-t1) * (t5-t1) + (t4-t2) * (t6-t2)) <= 0 && !dcmp((t3-t1)*(t6-t2) - (t5-t1)*(t4-t2));
}
bool onSegment(double t1, double t2, pnt a, pnt b) {
        return onSegment(t1, t2, a.x, a.y, b.x, b.y);
}
pkt p[1<<18], s[1<<18];
int main() {
        int n, A, B, mx1 = 0, mx2 = 0;
        cin >> n >> A >> B;
        for(int i = 0, t1, t2; i < n; ++i) {
                scanf("%d%d", &t1, &t2);
                chmax(mx1, t1);
                chmax(mx2, t2);
                p[i] = pnt(t1, t2);
        }
        p[n++] = pkt(mx1, 0);
        p[n++] = pkt(0, mx2);
        sort(p, p + n, cmp);

        int top = 0;
        for(int i = 0; i < n; ++i) {
                if(i && p[i].y && p[i].x && p[i].x == p[i-1].x) continue;
                while(top && s[top-1].y < p[i].y) --top;
                while(top > 1 && ((s[top-1]-s[top-2])^(p[i]-s[top-2])) >= 0) --top;
                s[top++] = p[i];
        }
        //for(int i = 0; i < top; ++i) OUT(s[i]);

        double t1, t2;
        pnt zero = pnt(0, 0), tar = pnt(A, B);
        for(int i = 1; i < top; ++i) {
                if(GetLineIntersection(zero, tar, s[i-1], s[i] - s[i-1], t1, t2)) {
                        if(onSegment(t1, t2, s[i-1], s[i])) {
                                //OUT(t1); OUT(t2); OUT(sqrt(t1*t1 + t2*t2));
                                printf("%.15f\n", (double)(tar.length() / sqrt(t1*t1 + t2*t2)));
                                return 0;
                        }
                }
        }
}

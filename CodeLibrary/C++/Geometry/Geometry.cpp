namespace doubleGeometry {
    const double EPS = 1e-5;
    int eps(e){if(fabs(e)<EPS)return 0;if(e>EPS)return 1;return -1;}
    //head 
    struct Point {
        double x, y;
        Point(double x = 0, double y = 0) : x(x), y(y){ }
        void read() {
            scanf("%lf%lf", &x, &y);
        }
        void output() {
            printf("x:%f y:%f\n", x, y);
        }
        int dim() const {
            return !(y > 0 || (y == 0 && x >= 0));
        }
    };
    typedef Point Vector;
    Point operator - (const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    }
    Point operator + (const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    bool operator == (const Point &a, const Point &b) {
        return !eps(a.x - b.x) && !eps(a.y - b.y);
    }
    bool operator != (const Point &a, const Point &b) {
        return !(a == b);
    }
    //数量积
    Point operator * (const Point &a, int p) {    
        return Point(a.x * p, a.y * p);
    }
    //叉乘
    double operator ^ (const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }
    bool operator < (const Point &a, const Point &b) {
        return a.dim() < b.dim() || (a.dim() == b.dim() && eps(a^b) > 0);
    }
}

namespace intGeometry {
    struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y){ }
        void read() {
            scanf("%d%d", &x, &y);
        }
        void output() {
            printf("x:%d y:%d\n", x, y);
        }
        int dim() const {
            return !(y > 0 || (y == 0 && x >= 0));
        }
    };
    typedef Point Vector;
    Point operator - (const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    }
    Point operator + (const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    bool operator == (const Point &a, const Point &b) {
        return !eps(a.x - b.x) && !eps(a.y - b.y);
    }
    bool operator != (const Point &a, const Point &b) {
        return !(a == b);
    }
    //数量积
    Point operator * (const Point &a, int p) {    
        return Point(a.x * p, a.y * p);
    }
    //叉乘
    double operator ^ (const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }
    bool operator < (const Point &a, const Point &b) {
        return a.dim() < b.dim() || (a.dim() == b.dim() && a^b > 0);
    }
}


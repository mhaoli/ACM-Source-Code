struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y){ }
        void read() {
                scanf("%d%d", &x, &y);
        }
        void output() {
                printf("%d %d\n", x, y);
        }
        int dim() const {
                return y > 0 || (y == 0 && x >= 0);
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
        return a.x == b.x && a.y == b.y;
}
bool operator != (const Point &a, const Point &b) {
        return !(a == b);
}
//数量积
Point operator * (const Point &a, int p) {    
        return Point(a.x * p, a.y * p);
}
//叉乘
long long operator ^ (const Point &a, const Point &b) {
        return (long long)a.x * b.y - (long long)a.y * b.x;
}
bool operator < (const Point &a, const Point &b) {
        if(a.dim() != b.dim()) {
                return a.dim() > b.dim();
        } else {
                return (a ^ b) > 0;
        }
}

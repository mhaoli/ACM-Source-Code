#include<cstdio>
using namespace std;
const int N = 9 + (int)1e6;
int q[N+10], op[N+10], cnt[N+10];
void add (int &x){
    if (++x >= N) x = 0;
}
void del (int &x){
    if (--x < 0) x = N-1;
}
void Read(int &ret){
    bool ok = 0, u = 0;
	for(ret = 0; ;){
		int c = getchar();
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
        else if (c == '-') u = 1;
		else if (ok){ if (u) ret *= -1; return ; }
	}
}
int main(){
    int n, i; Read (n);
    for (i = 0; i < n; ++i) Read (op[i]); op[n] = -2;
    for (i = n-1; i >= 0; --i) cnt[i] = cnt[i+1] + (op[i]==-1);
    for (int *t=op, *tcnt=cnt, tsz, sz = 0, l = 0, r = -1; ; ++t, ++tcnt){
        if (*t > 0) add(r), q[r]=*t, ++sz;
        else if (*t == 0){
            for (i = r, tsz=sz; tsz > 0 && sz < *tcnt; del(i), --tsz, ++sz)
                del(l), q[l]=q[i];
        } else if (*t == -1){
            printf ("%d\n", q[r]);
            del(r); --sz;
        } else break;
    }
    return 0;
}

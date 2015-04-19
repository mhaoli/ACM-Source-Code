#include<bits/stdc++.h>
const int N = 9 + (int)2e5;
const long long inf = 1ll<<60;
int top;
char stk[N];
void output (int cnt, char c){
        while (cnt--) stk[top++] = c;
}
int main(){
        int n, m;
        scanf ("%d%d", &n, &m);
        int pos = 0;
        long long ans = -inf, tmp, t1, t2;
        for (int i = 1; i <= n + 1; ++i){
                tmp = i == 1 ? 0 : i - 2 + (n - i + 2ll) * (n - i + 2);
                t2 = m % i; t1 = i - t2;
                tmp -= t1 * (m / i) * (m / i) + t2 * (m / i + 1) * (m / i + 1);
                if (ans < tmp) ans = tmp, pos = i;
        }

        std::cout << ans << std::endl;
        t2 = m % pos; t1 = pos - t2;
        output (m / pos, 'x'); --t1;
        for (int i = 1; i <= pos-1; ++ i){
                output (i == 1 ? n - pos + 2 : 1, 'o');
                if (t1) output (m / pos, 'x'), --t1;
                else output (m / pos + 1, 'x');
        }
        stk[top] = 0;
        puts (stk);
        return 0;
}

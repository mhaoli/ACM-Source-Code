#include<bits/stdc++.h>
const int N = 9 + (int)3e5;
int num[N];
std::pair<int, int> a[N];
int main(){
    int n, p;
    scanf ("%d%d", &n, &p);
    for (int i = 0; i < n; ++ i){
        scanf ("%d%d", &a[i].first, &a[i].second);
        if (a[i].first > a[i].second) std::swap (a[i].first, a[i].second);
        ++num[--a[i].first]; ++num[--a[i].second];
    }
    sort (a, a + n);
    a[n].first = a[n].second = -1;
    long long ans = 0;
    for (int t, i = 1, cnt = 1; i <= n; ++ i){
        if (a[i].first == a[i-1].first && a[i].second == a[i-1].second){
            ++cnt;
        } else{
            t = num[a[i-1].first] + num[a[i-1].second];
            if (t >= p && t-cnt < p) --ans;
            cnt = 1;
        }
    }
    std::sort (num, num + n);
    for (int pos, i = 0; i < n-1; ++i){
        pos = std::lower_bound (num+i+1, num+n, p-num[i]) - num;
        ans += n - pos;
    }
    printf ("%I64d\n", ans);
    return 0;
}

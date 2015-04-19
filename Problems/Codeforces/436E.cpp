#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (3e5);
int a[N], b[N];
int cnt[N<<1];
pair<int, int> p[N<<1];
vector<pair<int, int> > vec;
int main(){
    int n, w; scanf ("%d%d", &n, &w);
    for (int i = 0; i < n; ++i){
        scanf ("%d%d", a+i, b+i);
        a[i] <<= 1; b[i] <<= 1;
        if (a[i] <= b[i]>>1){
            p[i<<1].first = a[i];
            p[i<<1|1].first = b[i] - a[i];
        } else{
            p[i<<1].first = p[i<<1|1].first = b[i] >> 1;
        }
        p[i<<1].second = i << 1;
        p[i<<1|1].second = i << 1 | 1;
    }
    sort (p, p + (n<<1));
    long long ans = 0, tmp, mi;
    for (int i = 0; i < w; ++i) ans += p[i].first, cnt[p[i].second] = 1;
    if ((p[w-1].second & 1) == 0 && a[p[w-1].second>>1] != p[w-1].first){
        ans = ans - p[w-1].first + a[p[w-1].second>>1];
        mi = ans; 
        vec.clear ();
        for (int i = 0; i < n; ++i) if (i != p[w-1].second>>1){
            if (!cnt[i<<1]){
                tmp = ans - a[p[w-1].second>>1] + a[i];
                if (tmp < mi){
                    mi = tmp;
                    vec.clear ();
                    vec.push_back (make_pair (p[w-1].second, 0));
                    vec.push_back (make_pair (i << 1, 1));
                }
            } else if (!cnt[i<<1|1]){
                tmp = ans - a[p[w-1].second>>1] + b[i] - a[i];
                if (tmp < mi){
                    mi = tmp;
                    vec.clear ();
                    vec.push_back (make_pair (p[w-1].second, 0));
                    vec.push_back (make_pair (i << 1 | 1, 1));
                }

                tmp = ans - a[i] + b[p[w-1].second>>1] - a[p[w-1].second>>1];
                if (tmp < mi){
                    mi = tmp;
                    vec.clear ();
                    vec.push_back (make_pair (i << 1, 0));
                    vec.push_back (make_pair (p[w-1].second | 1, 1));
                }
            } else{
                tmp = ans + a[i] - b[i] + b[p[w-1].second>>1] - a[p[w-1].second>>1];
                if (tmp < mi){
                    mi = tmp;
                    vec.clear ();
                    vec.push_back (make_pair (i << 1 | 1, 0));
                    vec.push_back (make_pair (p[w-1].second|1, 1));
                }
            }
        }
        ans = mi;
        for (int i = 0; i < (int)vec.size(); ++i) cnt[vec[i].first] = vec[i].second;
    }
    printf ("%I64d\n", ans>>1);
    for (int i = 0; i < n; ++i) printf ("%d", cnt[i<<1] + cnt[i<<1|1]);
    puts ("");
    return 0;
}

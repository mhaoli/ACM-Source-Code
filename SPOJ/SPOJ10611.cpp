#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++ it)
#define out(x) cout<<#x<<" : "<<x<<endl;
using namespace std;
const int N = 1005;
const int mod = 10000;
set<int> st;
map<int, int> has;
int idx, a1[N], a2[N], b1[N], b2[N];
int ad[N<<3], de[N<<3], sum[N<<3], num[N<<3], cnt[N<<3];
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
int main(){
    int n, m, q;
    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d", a1 + i, a2 + i);
        st.insert (a1[i]); st.insert (a2[i]+1);
    }
    for (int i = 0; i < q; ++ i){
        scanf ("%d%d", b1 + i, b2 + i);
        st.insert (b1[i]-1); st.insert (b2[i]);
    }
    idx = 1;
    foreach (it, st) has[*it] = idx, num[idx++] = *it;
    for (int i = 0; i < m; ++ i){
        add (ad[has[a1[i]]], 1);
        add (cnt[has[a1[i]]], 1);
        add (de[has[a2[i]+1]], (a2[i] - a1[i] + 2) % mod);
        add (cnt[has[a2[i]+1]], mod - 1);
    }
    int t = 0, tot = 0;
    for (int i = 1; i < idx; ++ i){
        long long now = 2*t + (long long)(num[i] - num[i-1] - 1) * tot;
        if (now & 1){
            sum[i] = (now % mod) * (((num[i] - num[i-1]) >> 1) % mod) % mod;
        } else{
            sum[i] = ((now >> 1) % mod) * ((num[i] - num[i-1]) % mod) % mod;
        }
        add (sum[i], sum[i-1]);
        add (sum[i], mod - t);

        t = (now - t + tot + mod) % mod;
        add (t, ad[i]); add (t, mod - de[i]);
        add (tot, cnt[i]);
        add (sum[i], t);
    }
    for (int i = 0, j, k; i < q; ++ i){
        j = has[b1[i]-1]; k = has[b2[i]];
        printf ("%d\n", (sum[k] + mod - sum[j]) % mod);
    }
    return 0;
}

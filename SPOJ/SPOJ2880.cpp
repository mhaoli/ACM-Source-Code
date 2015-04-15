#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
using namespace std;
const int N = 9 + (int)1e5;
long long S;
vector<pair<int, int> > op[N];
set<pair<int, int> > st;
set<pair<int, int> >::iterator it;
void insert (pair<int, int> pr){
    it = st.lower_bound (pr);
    if (it->second >= pr.second) return;
    vector<set<pair<int, int> >::iterator> del;
    long long x = pr.first, y = pr.second, tx, ty, ly = it->second;
    while (it != st.begin ()){
        --it;
        tx = it->first; ty = it->second;
        S += (x - tx) * (y - ly);
        ly = ty; x = tx;
        if (ly < y) del.push_back (it);
        else break;
    }
    foreach (p, del) st.erase (*p); 
    st.insert (pr);
}
int main(){
    int n, m;
    while (scanf ("%d%d", &n, &m), n || m){
        for (int i = 0; i <= m+1; ++i) op[i].clear ();
        for (int i = 0, x, y, z; i < n; ++i){
            scanf ("%d%d%d", &x, &y, &z);
            op[x].push_back (make_pair (y, z));
        }
        S = 0;
        long long ans = 0;
        st.clear ();
        st.insert (make_pair (m+1, 0));
        st.insert (make_pair (0, m+1));
        for (int x = m; x; --x){
            sort (op[x].begin(), op[x].end(), greater<pair<int,int> >());
            foreach (p, op[x]){
                if (p == op[x].begin() || p->first != (p-1)->first)
                    insert (*p);
            }
            ans += S;
        }
        cout << (long long)m * m * m - ans << endl;
    }
    return 0;
}

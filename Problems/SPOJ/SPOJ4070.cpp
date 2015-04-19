#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)1e5;
vector<pair<int, int> > vec;
bool can[N<<1];
bool check (int fg, int res){
    for (int i = 0; i < (int)vec.size(); ++i){
        can[i] = 0;
    }
    bool cur = 1;
    for (int id, tag, cnt = 0, i = 0; i < (int)vec.size(); ++i){
        id = vec[i].second < 0 ? -vec[i].second - 1 : vec[i].second;
        tag = vec[i].second < 0 ? -1 : 1;
        if (tag == 1){
            if (id == fg) can[id] = 0;
            else can[id] = cur;
            if (++cnt == res) cur = 0;
        } else{
            --cnt;
            cur |= can[id];
        }
    }
    return can[fg^1];
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n; scanf ("%d", &n);
        pair<int, int> A, B;
        vec.clear ();
        for (int i = 0, u, v; i < n; ++i){
            scanf ("%d%d", &u, &v);
            if (!i) A = make_pair (u, v);
            if (i == 1) B = make_pair (u, v);
            vec.push_back (make_pair (u, i));
            vec.push_back (make_pair (v, -(i+1)));
        }
        int ans = 0;
        sort (vec.begin(), vec.end());
        //for (int i = 0; i < (int)vec.size(); ++i)
            //printf ("%d %d\n", vec[i].first, vec[i].second);
        for (int i = 0, cnt = 0; i < (int)vec.size(); ++i){
            cnt += vec[i].second < 0 ? -1 : 1;
            ans = max (ans, cnt);
        }
        ans += !check (A > B, ans);
        printf ("%d\n", ans);
    }
    return 0;
}

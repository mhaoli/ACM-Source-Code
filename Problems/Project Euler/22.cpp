/*
 * Author:  Plumrain
 * Created Time:  2014-01-17 10:59
 * File Name: 22.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define out(x) cout<<#x<<":"<<(x)<<endl
typedef vector<string> vs;
typedef long long int64;
vs v;
int64 gao(string s)
{
    int64 ret = 0;
    for (int i = 0; i < sz(s); ++ i) ret += s[i] - 'A' + 1;
    return ret;
}
int main()
{
    string t; cin >> t;
    string s;
    int pos = 0;
    while (pos < sz(t)){
        while (pos < sz(t) && !(t[pos] >= 'A' && t[pos] <= 'Z')) ++ pos;
        s.clear();
        for (int i = pos; i < sz(t); ++ i){
            if (!(t[i] >= 'A' && t[i] <= 'Z')){
                pos = i+1;
                break;
            }
            s.pb (t[i]);
        }
        if (sz(s)) v.pb(s);
    }
    out (v[sz(v)-1]);
    sort(all(v));
    int64 ans = 0;
    for (int64 i = 0; i < sz(v); ++ i) ans += (i+1) * gao(v[i]);
    out (ans);
    return 0;
}

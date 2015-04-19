/*
 * Author:  Plumrain
 * Created Time:  2014/10/6 13:52:11
 * File Name: ZOJ3661.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define UL unsigned int
const int N = 9 + (int)1e5;
const UL seed = 173;
const ll mod = 777777777;

UL rh[N], hh[N];

int calc_hash (int l, int r){
    return l ? rh[r] - rh[l-1]*hh[r-l+1] : rh[r];
}

int manacher (char *str, int *len, int n){  //len[i] means the max palindrome length centered i/2
    for (int i = 0; i < 2*n; ++ i) len[i] = 0;
    int mx = 0;
    for (int i = 0, j = 0, k; i < 2*n; i += k, j = max (j-k, 0)){
        while (i - j >= 0 && i + j + 1 < 2*n && str[(i-j) / 2] == str[(i+j+1) / 2]) ++ j;
        len[i] = j;
        chmax (mx, j);
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; ++ k){
            len[i+k] = min (len[i - k], j - k);
        }
    }
    return mx;
}

struct hashTable{
	const static UL Mod = 500009;
	struct nod{
		nod *nxt;
		UL key;
		int pos;
        void add (UL num, int p, nod*n){
            key = num; pos = p; nxt = n;
        }
	}memo[N<<2], *bat, *head[Mod];

	void reset(){
		memset(head, 0, sizeof head);
        bat = memo;
	}
    //map[num] = pos;
	void insert(UL num, int pos){
		UL x = num%Mod;
        bat->add (num, pos, head[x]);
		head[x] = bat++;
	}
	int find(UL num){
		UL x = num%Mod;
		for(nod* p = head[x]; p; p = p->nxt)
			if(p->key == num) return p->pos;
		return -1; // not found
	}
}ha;

struct nod{
    nod *ch[26];
    int v;
    nod *go(int c);
}*bat, memo[N<<1], *rt;

UL key;

void newnod (nod *&o){
    o = bat++; memset (o->ch, 0, sizeof o->ch); o->v = 0; 
}
nod *nod::go(int c){
    key = key * seed + c + 1;
    if (!ch[c]){
        newnod (ch[c]);
        ha.insert (key, ch[c] - memo);
    }
    return ch[c];
}
void trie_init(){
    bat = memo; newnod (rt);
}
void insert (char *s, int mid, int l, int r, nod*x){
    key = mid < l ? calc_hash (mid, l-1) : 0;
    for (int i = l; i <= r; ++ i) x = x->go(s[i]-'a');
    ++ x->v;
}

char s[N];
int len[N<<1], cnt[N], val[100], tot;
pii res[N];

int dfs(int now, nod*u, int ke){
    int cnt = u->v;
    rep (i, 0, 25) if (u->ch[i]){
        cnt += dfs ((now + (ll)ke * val[i]) % mod, u->ch[i], ke * 26ll % mod);
    }
    if (u != rt && cnt){
        res[tot].x = now;
        res[tot++].y = cnt;
    }
    return cnt;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    rep (i, 0, N-1) hh[i] = i ? hh[i-1] * seed : 1;

    int T; scanf ("%d", &T);
    while (T--){
        int L, q; scanf ("%d%d", &L, &q);
        scanf ("%s", s);
        rep (i, 0, L-1){
            rh[i] = i ? rh[i-1]*seed + s[i]-'a'+1 : s[i]-'a'+1;
        }
        manacher (s, len, L);

        ha.reset ();
        trie_init ();
        rep (i, 0, (L<<1)-1) if (len[i]){
            int r = (i>>1) + (len[i]>>1), l = r - len[i] + 1;
            int x = ((l + r) >> 1) + ((r-l) & 1), tr = r, pos;
            for (; tr >= x && -1 == (pos = ha.find (calc_hash (x, tr))); -- tr);
            insert (s, x, tr + 1, r, ~pos ? &memo[pos] : rt);
        }

        while (q--){
            ll k; scanf ("%lld", &k);
            rep (i, 0, 25) scanf ("%d", val + i);
            tot = 0;
            dfs (0, rt, 1);
            sort (res, res + tot);
            ll num = 0;
            rep (i, 0, tot-1){
                num += res[i].y;
                if (num >= k){
                    printf ("%d\n", res[i].x); break;
                }
            }
        }
        puts ("");
    }
    return 0;
}


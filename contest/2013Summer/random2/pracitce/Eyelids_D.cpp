/*
 * Author:  Eyelids
 * Created Time:  2013/8/5 15:36:45
 * File Name: d.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
char x[20][20];
int y[20][20];
int f[1 << 16];
int n, m;
int w[110];

void Init() {
        for (int i = 1; i <= 10; i ++)
            scanf("%s", x[i] + 1);  
         
        n = 0;
        for (int i = 1; i <= 10; i ++)
            for (int j = 1; j <= 10; j ++) {
                if (x[i][j] == 'e')
                    y[i][j] = n ++;
            }
        
        m = 0;
        for (int i = 1; i <= 10; i ++)
            for (int j = 1; j <= 10; j ++) {
                    bool flag = true;
                    int sta = 0;                    
                    for (int a = i - 1; a <= i + 1; a ++)
                        for (int b = j - 1; b <= j + 1; b ++) {
                            if (x[a][b] == 'g') {
                                flag = false;
                                break;
                            }                
                            if (x[a][b] == 'e') {
                                sta |= (1 << y[a][b]);
                            }
                        }  
                    if (i ==2 && j == 3)
			            cout << sta << endl;
                    if (flag && sta) w[++ m] = sta;      
                
            }
}

int Dfs(int cur) {
        if (cur == (1 << n) - 1) return 0;
        if (f[cur] != -1) return f[cur];
         
        f[cur] = 100;
        int next;
        for (int i = 1; i <= m; i ++) {
            next = cur | w[i];
            
            if (next == cur) continue;
            f[cur] = min(f[cur], Dfs(next) + 1);
        }
        
        return f[cur];    
}

void Outit() { 
        int sum;
        int a = 0, b = 100;
        for (int sta = 0; sta < (1 << n); sta ++) {
            if (Dfs(sta) >= 100) continue;
             
            sum = 0;
            for (int j = 0; j < n; j ++)
                if (sta & (1 << j)) sum ++;
            sum = n - sum;
            
            if (sum > a) {
                a = sum;
                b = min(b, Dfs(sta));
            }
            if (sum == a) {
                b = min(b, Dfs(sta));
            }
        }
       
        if (b >= 100) b = 0;

        cout <<a<<" "<<b<<endl;
}

int main() {
        freopen ("a.in","r",stdin);
        int T;
        scanf("%d", &T);
        while (T --) {
            Init();
        
            memset(f, -1, sizeof(f));
        
            Outit();
        }  
    
        return 0;
}

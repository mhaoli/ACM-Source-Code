//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
int x,y,Sx,Sy,Ex,Ey;
bool an[45][45];

void DFS()
{
	
}

int main()
{
	//freopen("a.in","r",stdin);
	int t;
	while( t -- ){
		memset(an,false,sizeof(an));
		cin>>x>>y;
		char xx[45];
		for( int i = 1 ; i <= y ; i ++ ){
			cin>>xx;
			for( int j = 1 ; j <= x ; j ++ ){
				if( xx[j-1] == '.' )
					an[i][j] = true;
				if( xx[j-1] == 'S' ){
					an[i][j] = true;
					Sx = j ; Sy = i ;
				}
				if( xx[j-1] == 'E' ){
					an[i][j] = true;
					Ex = j ; Ey = i ;
				}
			}
		}
		int ans1 = DFS(Sx,Sy,'l') , ans2 = DFS(Sx,Sy,'r') , ans3 = BFS(Sx,Sy);
		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}	
	return 0;
}

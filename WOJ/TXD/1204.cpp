/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/2 16:26:39
 * File Name: 1204.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
const int Max_N = 9 + (int)5e5;
int a[Max_N];
int main()
{
        for(int n, ans, cnt, last, ans_cnt; scanf("%d", &n) != EOF; ) {
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                sort(a, a + n);
                last = ans = a[0]; cnt = ans_cnt = 1;
                for(int i = 1; i < n; ++i) {
                        if(a[i] == last) ++cnt;
                        if(cnt > ans_cnt) {
                                ans_cnt = cnt; ans = last;
                        }
                        if(a[i] != last) cnt = 1, last = a[i];
                }
                printf("%d\n", ans);
        }
        return 0;
}

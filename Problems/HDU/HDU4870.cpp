/* 用于求整数解得方程组. */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-10;
template<class T> int sgn (T x){ return (x > eps) - (x < -eps);}
const int maxn = 30;
int equ, var; // 有equ个方程，var个变元。增广阵行数为equ, 分别为0到equ - 1，列数为var + 1，分别为0到var.
double a[maxn][maxn];
double x[maxn]; // 解集.
bool free_x[maxn]; // 判断是否是不确定的变元.
int free_num;
void Debug(void)
{
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
int Gauss(void)
{
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行.
    int col; // 当前处理的列.
    double tb;
    double temp;
    int free_x_num;
    int free_index;
    // 转换为阶梯阵.
    col = 0; // 当前处理的列.
    for (k = 0; k < equ && col < var; k++, col++)
    { // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r = k;
        for (i = k + 1; i < equ; i++)
        {
            if (fabs(a[i][col]) > fabs(a[max_r][col])) max_r = i;
        }
        if (max_r != k)
        { // 与第k行交换.
            for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if (sgn (a[k][col]) == 0)
        { // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--; continue;
        }
        for (i = k + 1; i < equ; i++)
        { // 枚举要删去的行.
            if (sgn (a[i][col]))
            {
                tb = a[i][col] / a[k][col];
                for (j = col; j < var + 1; j++)
                {
                    a[i][j] = a[i][j] - a[k][j] * tb;
                }
            }
        }
    }
    //Debug();
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (i = k; i < equ; i++)
    { // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
        if (sgn (a[i][col])) return -1;
    }
    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k < var)
    {
        // 首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (i = k - 1; i >= 0; i--)
        {
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            free_x_num = 0; // 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            for (j = 0; j < var; j++)
            {
                if (sgn (a[i][j]) && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue; // 无法求解出确定的变元.
            // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            temp = a[i][var];
            for (j = 0; j < var; j++)
            {
                if (sgn (a[i][j]) && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        return var - k; // 自由变元有var - k个.
    }
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j < var; j++)
        {
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        x[i] = temp / a[i][i];
    }
    return 0;
}
double d[30][30];
int main(){
    //freopen("a.out","w",stdout);
    double p;
    while (scanf ("%lf", &p) != EOF){
        for (int i = 0; i < 20; ++ i) d[20][i] = 0;
        for (int i = 19; i >= 0; -- i){
            memset (a, 0, sizeof a);
            memset (x, 0, sizeof x);
            equ = i + 1;
            var = i + 1;
            memset (free_x, 1, sizeof free_x);
            for (int j = i; j >= 0; -- j){
                if (j == i){
                    a[j][j] += -1;
                    a[j][j+1] += -(d[i+1][j] * p + 1);
                    a[j][max (j-2, 0)] += 1 - p;
                } else{
                    a[j][i+1] += -1;
                    a[j][j] += -1;
                    a[j][j+1] += p;
                    a[j][max (j-2, 0)] += 1 - p;
                }
            }
            //Debug ();
            Gauss ();
            for (int j = 0; j <= i; ++ j)
                d[i][j] = x[j];
        }
        printf ("%.7f\n", d[0][0]);
    }
    return 0;
}

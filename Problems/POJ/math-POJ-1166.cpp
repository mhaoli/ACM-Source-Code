/*
 * Author:  Plumrain
 * Created Time:  2013-10-08 16:26
 * File Name: math-POJ-1166.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl

int x[10], sum;
int a[10][10]={
};

void gauss()
{
    sum = 0;
    int row = 0, col = 0;
    while (row < 9 && col < 9){
        int flag = row;
        if (!a[row][col])
            for (int i = row+1; i < 9; ++ i)
                if (a[i][col] && !a[flag][col]) flag = i;
        if (flag != row) for (int i = col; i <= 9; ++ i)
            swap (a[row][i], a[flag][i]);
        if (!a[row][col]){++ col; continue;}

        for (int i = row+1; i < 9; ++ i){
            int ta = a[i][col], tb = a[row][col];
            for (int j = col; j <= 9; ++ j){
                a[i][j] = (a[i][j] * tb - a[row][j] * ta) % 4;
                if (a[i][j] < 0) a[i][j] += 4;
            }
        }
        ++ col; ++ row;
    }

    for (int i = 8; i >= 0; -- i){
        int tmp = a[i][9];
        for (int j = i+1; j < 9; ++ j)
            tmp -= a[i][j] * x[j];
        tmp %= 4; if (tmp < 0) tmp += 4;
        for (x[i] = 0; x[i] < 4; ++ x[i])
            if ((x[i]*a[i][i]%4 + 4) % 4 == tmp)
                break;
        x[i] %= 4;
        sum += x[i];
    }
}

int main()
{
    CLR (a);
    a[0][0]=a[1][0]=a[3][0]=a[4][0]=1;  
    a[0][1]=a[1][1]=a[2][1]=1;  
    a[1][2]=a[2][2]=a[4][2]=a[5][2]=1;  
    a[0][3]=a[3][3]=a[6][3]=1;  
    a[1][4]=a[3][4]=a[4][4]=a[5][4]=a[7][4]=1;  
    a[2][5]=a[5][5]=a[8][5]=1;  
    a[3][6]=a[4][6]=a[6][6]=a[7][6]=1;  
    a[6][7]=a[7][7]=a[8][7]=1;  
    a[4][8]=a[5][8]=a[7][8]=a[8][8]=1;  

    for (int i = 0; i < 9; ++ i){
        scanf ("%d", &a[i][9]);
        a[i][9] = (4 - a[i][9]) % 4;
    }

    gauss();
    
    for (int i = 0; i < 9; ++ i)
        while (x[i]){
            printf ("%d", i+1);
            -- x[i]; -- sum;
            printf (sum>0 ? " " : "\n");
        }
    return 0;
}
